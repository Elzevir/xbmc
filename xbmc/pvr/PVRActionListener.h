#pragma once

/*
 *      Copyright (C) 2005-2015 Team XBMC
 *      http://xbmc.org
 *
 *  This Program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This Program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with XBMC; see the file COPYING.  If not, see
 *  <http://www.gnu.org/licenses/>.
 *
 */

#include "interfaces/IActionListener.h"
#include "settings/lib/ISettingCallback.h"

namespace PVR
{

class CPVRActionListener : public IActionListener, public ISettingCallback
{
public:

  void Init();
  void Deinit();

  static CPVRActionListener &GetInstance();

  // IActionListener implementation
  bool OnAction(const CAction &action) override;

  // ISettingCallback implementation
  void OnSettingChanged(const CSetting *setting) override;
  void OnSettingAction(const CSetting *setting) override;

private:
  CPVRActionListener() = default;
  ~CPVRActionListener() = default;
  CPVRActionListener(const CPVRActionListener&) = delete;
  CPVRActionListener& operator=(const CPVRActionListener&) = delete;
};

} // namespace PVR
