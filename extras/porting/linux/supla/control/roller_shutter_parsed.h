#ifndef EXTRAS_PORTING_LINUX_SUPLA_CONTROL_ROLLER_SHUTTER_PARSED_H_
#define EXTRAS_PORTING_LINUX_SUPLA_CONTROL_ROLLER_SHUTTER_PARSED_H_

#include <supla/control/control_payload.h>
#include <supla/control/roller_shutter_interface.h>
#include <supla/sensor/sensor_parsed.h>

namespace Supla {

namespace Control {
class RollerShutterParsed : public Sensor::SensorParsed<RollerShutterInterface>,
                    public Payload::ControlPayload<RollerShutterInterface> {
 public:
  RollerShutterParsed(Supla::Parser::Parser *parser,
              Supla::Payload::Payload *payload);

 protected:
  uint32_t lastReadTime = 0;
  bool useOfflineOnInvalidState = false;
};

};  // namespace Control
};  // namespace Supla

#endif //EXTRAS_PORTING_LINUX_SUPLA_CONTROL_ROLLER_SHUTTER_PARSED_H_