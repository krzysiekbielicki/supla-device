#include "roller_shutter_parsed.h"

Supla::Control::RollerShutterParsed::RollerShutterParsed(
    Supla::Parser::Parser *parser,
    Supla::Payload::Payload *payload)
    : Supla::Sensor::SensorParsed<Supla::Control::RollerShutterInterface>(parser),
      Supla::Payload::ControlPayload<Supla::Control::RollerShutterInterface>(payload) {
  
}