#ifndef EXTRAS_PORTING_LINUX_SUPLA_CONTROL_ROLLER_SHUTTER_PARSED_H_
#define EXTRAS_PORTING_LINUX_SUPLA_CONTROL_ROLLER_SHUTTER_PARSED_H_

#include <supla/control/control_payload.h>
#include <supla/control/roller_shutter.h>
#include <supla/payload/payload.h>
#include <supla/sensor/sensor_parsed.h>

#include <string>

namespace Supla {

namespace Control {
class RollerShutterParsed : public Sensor::SensorParsed<RollerShutterInterface>,
                            public Payload::ControlPayload<RollerShutterInterface> {
 public:
  RollerShutterParsed(Supla::Parser::Parser *parser,
                      Supla::Payload::Payload *payload);

 protected:
  uint32_t lastReadTime = 0;
};
};  // namespace Control
};  // namespace Supla

#endif