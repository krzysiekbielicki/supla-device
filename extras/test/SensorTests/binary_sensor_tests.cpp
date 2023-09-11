/*
   Copyright (C) AC SOFTWARE SP. Z O.O

   This program is free software; you can redistribute it and/or
   modify it under the terms of the GNU General Public License
   as published by the Free Software Foundation; either version 2
   of the License, or (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
   */

#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <supla/sensor/virtual_binary.h>
#include <simple_time.h>

TEST(BinarySensorTests, BasicTest) {
  SimpleTime time;
  Supla::Sensor::VirtualBinary sensor;

  EXPECT_EQ(sensor.getValue(), false);
  EXPECT_EQ(sensor.getChannel()->getValueBool(), false);

  sensor.setServerInvertLogic(true);

  EXPECT_EQ(sensor.getValue(), false);
  EXPECT_EQ(sensor.getChannel()->getValueBool(), true);

  sensor.set();

  for (int i = 0; i < 50; ++i) {
    sensor.iterateAlways();
    time.advance(100);
  }

  EXPECT_EQ(sensor.getValue(), true);
  EXPECT_EQ(sensor.getChannel()->getValueBool(), false);

  sensor.setServerInvertLogic(false);

  EXPECT_EQ(sensor.getValue(), true);
  EXPECT_EQ(sensor.getChannel()->getValueBool(), true);
}

