#line ${linenum} "${filename}"
// *********************************************************
// 
// File autogenerated for the ${pkgname} package 
// by the dynamic_reconfigure package.
// Please do not edit.
// 
// ********************************************************/

/***********************************************************
 * Software License Agreement (BSD License)
 *
 *  Copyright (c) 2008, Willow Garage, Inc.
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   * Neither the name of the Willow Garage nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 ***********************************************************/

// Author: Blaise Gassend


#ifndef __${uname}RECONFIGURATOR_H__
#define __${uname}RECONFIGURATOR_H__

#include <dynamic_reconfigure/reconfigurator.h>
#include <${pkgname}/${name}Config.h>
#include <${pkgname}/Get${name}Config.h>
#include <${pkgname}/Set${name}Config.h>

#include <boost/thread.hpp>
#include <limits>

namespace ${pkgname}
{
  class ${name}ConfigManipulator
  {
  public:
    typedef ${pkgname}::Get${name}Config GetService;
    typedef ${pkgname}::Set${name}Config SetService;
    typedef ${pkgname}::${name}Config ConfigType;
  
    static const ConfigType &getDefaults()
    {
      initialize();
      return defaults;
    }

    static const ConfigType &getMin()
    {
      initialize();
      return min;
    }

    static const ConfigType &getMax()
    {
      initialize();
      return max;
    }

    /**
     * Reads configuration from the configuration server.
     * Undefined values are left unmodified.
     *
     * \param nh ros::NodeHandle through which to access the name server.
     * \param config Reference to the configuration to modify
     */
    static void readFromParamServer(ros::NodeHandle &nh, ConfigType &config)
    {
$readparam
#line ${linenum} "${filename}"
    }

    static void writeToParamServer(ros::NodeHandle &nh, const ConfigType &config)
    {
$writeparam
#line ${linenum} "${filename}"
    }
    
    static int getChangeLevel(const ConfigType &config1, const ConfigType &config2)
    {
      int changelvl = 0;
$changelvl
#line ${linenum} "${filename}"
      return changelvl;
    }

    static void clamp(ConfigType &config)
    {
$clamp
#line ${linenum} "${filename}"
    }
  
  private:
    static bool initialized;
    static boost::mutex initializing;
    static void initialize()
    {
      if (initialized) // Test without taking the lock for speed.
        return;
      
      boost::mutex::scoped_lock lock(initializing);

      if (initialized) // Make sure initialization didn't happen before we grabbed the lock.
        return;

$defminmax
    }

    static ConfigType defaults;
    static ConfigType min;
    static ConfigType max;
  };

  typedef dynamic_reconfigure::Reconfigurator<${name}ConfigManipulator> ${name}Reconfigurator;

  bool ${name}ConfigManipulator::initialized = false;
  boost::mutex  ${name}ConfigManipulator::initializing;
  ${name}ConfigManipulator::ConfigType ${name}ConfigManipulator::defaults;
  ${name}ConfigManipulator::ConfigType ${name}ConfigManipulator::min;
  ${name}ConfigManipulator::ConfigType ${name}ConfigManipulator::max;
}

#endif // __${uname}RECONFIGURATOR_H__
