#include "roller_shutter_parsed.h"

#include <supla/log_wrapper.h>
#include <supla/time.h>
#include <supla/control/output_interface.h>
#include <supla/log_wrapper.h>

#include <supla/sensor/binary_parsed.h>

#include <cstdio>

Supla::Control::RollerShutterParsed(
    Supla::Parser::Parser *parser,
    Supla::Payload::Payload *payload)
    : Supla::Sensor::SensorParsed<Supla::Control::RollerShutterInterface>(parser),
      Supla::Payload::ControlPayload<Supla::Control::RollerShutterInterface>(payload) {
  channel.setType(SUPLA_CHANNELTYPE_RELAY);
  channel.setDefault(SUPLA_CHANNELFNC_CONTROLLINGTHEROLLERSHUTTER);
  channel.setFuncList(SUPLA_BIT_FUNC_CONTROLLINGTHEROLLERSHUTTER |
                      SUPLA_BIT_FUNC_CONTROLLINGTHEROOFWINDOW |
                      SUPLA_BIT_FUNC_TERRACE_AWNING |
                      SUPLA_BIT_FUNC_ROLLER_GARAGE_DOOR |
                      SUPLA_BIT_FUNC_CURTAIN |
                      SUPLA_BIT_FUNC_PROJECTOR_SCREEN);
  channel.setFlag(SUPLA_CHANNEL_FLAG_RS_SBS_AND_STOP_ACTIONS);
  channel.setFlag(SUPLA_CHANNEL_FLAG_CALCFG_RECALIBRATE);
  channel.setFlag(SUPLA_CHANNEL_FLAG_RUNTIME_CHANNEL_CONFIG_UPDATE);

void Supla::Control::RollerShutterParsed::onInit() {
  RollerShutter::onInit();
  registerActions();
  handleGetChannelState(nullptr);
}

void Supla::Control::RollerShutterParsed::close() {
  Supla::Control::RollerShutterInterface::close();
  
  payload->setOn(parameter2Key[Supla::Payload::State], setOnValue);
}