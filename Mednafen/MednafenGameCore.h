/*
 Copyright (c) 2013, OpenEmu Team
 
 
 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:
     * Redistributions of source code must retain the above copyright
       notice, this list of conditions and the following disclaimer.
     * Redistributions in binary form must reproduce the above copyright
       notice, this list of conditions and the following disclaimer in the
       documentation and/or other materials provided with the distribution.
     * Neither the name of the OpenEmu Team nor the
       names of its contributors may be used to endorse or promote products
       derived from this software without specific prior written permission.
 
 THIS SOFTWARE IS PROVIDED BY OpenEmu Team ''AS IS'' AND ANY
 EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 DISCLAIMED. IN NO EVENT SHALL OpenEmu Team BE LIABLE FOR ANY
 DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#import <Foundation/Foundation.h>
#import <PVSupport/PVEmulatorCore.h>

@class OERingBuffer;

typedef NS_ENUM(int, PVPSXButton)
{
    OEPSXButtonUp,
    OEPSXButtonDown,
    OEPSXButtonLeft,
    OEPSXButtonRight,
    OEPSXButtonTriangle,
    OEPSXButtonCircle,
    OEPSXButtonCross,
    OEPSXButtonSquare,
    OEPSXButtonL1,
    OEPSXButtonL2,
    OEPSXButtonL3,
    OEPSXButtonR1,
    OEPSXButtonR2,
    OEPSXButtonR3,
    OEPSXButtonStart,
    OEPSXButtonSelect,
    OEPSXButtonAnalogMode,
    OEPSXLeftAnalogUp,
    OEPSXLeftAnalogDown,
    OEPSXLeftAnalogLeft,
    OEPSXLeftAnalogRight,
    OEPSXRightAnalogUp,
    OEPSXRightAnalogDown,
    OEPSXRightAnalogLeft,
    OEPSXRightAnalogRight,
    OEPSXButtonCount
};

typedef enum _OEWSButton
{
    OEWSButtonX1, // Up
    OEWSButtonX3, // Down
    OEWSButtonX4, // Left
    OEWSButtonX2, // Right
    OEWSButtonY1,
    OEWSButtonY3,
    OEWSButtonY4,
    OEWSButtonY2,
    OEWSButtonA,
    OEWSButtonB,
    OEWSButtonStart,
    OEWSButtonSound,
    OEWSButtonCount
} OEWSButton;

typedef enum _OEVBButton
{
    OEVBButtonLeftUp,
    OEVBButtonLeftDown,
    OEVBButtonLeftLeft,
    OEVBButtonLeftRight,
    OEVBButtonRightUp,
    OEVBButtonRightDown,
    OEVBButtonRightLeft,
    OEVBButtonRightRight,
    OEVBButtonL,
    OEVBButtonR,
    OEVBButtonA,
    OEVBButtonB,
    OEVBButtonStart,
    OEVBButtonSelect,
    OEVBButtonCount
} OEVBButton;

typedef enum _OEPCFXButton
{
    OEPCFXButtonUp,
    OEPCFXButtonDown,
    OEPCFXButtonLeft,
    OEPCFXButtonRight,
    OEPCFXButton1,
    OEPCFXButton2,
    OEPCFXButton3,
    OEPCFXButton4,
    OEPCFXButton5,
    OEPCFXButton6,
    OEPCFXButtonRun,
    OEPCFXButtonSelect,
    OEPCFXButtonCount,
} OEPCFXButton;

typedef enum _OEPCECDButton
{
    OEPCECDButtonUp,
    OEPCECDButtonDown,
    OEPCECDButtonLeft,
    OEPCECDButtonRight,
    OEPCECDButton1,
    OEPCECDButton2,
    OEPCECDButton3,
    OEPCECDButton4,
    OEPCECDButton5,
    OEPCECDButton6,
    OEPCECDButtonRun,
    OEPCECDButtonSelect,
    OEPCECDButtonMode,
    OEPCECDButtonCount
} OEPCECDButton;

typedef enum _OEPCEButton
{
    OEPCEButtonUp,
    OEPCEButtonDown,
    OEPCEButtonLeft,
    OEPCEButtonRight,
    OEPCEButton1,
    OEPCEButton2,
    OEPCEButton3,
    OEPCEButton4,
    OEPCEButton5,
    OEPCEButton6,
    OEPCEButtonRun,
    OEPCEButtonSelect,
    OEPCEButtonMode,
    OEPCEButtonCount
} OEPCEButton;

typedef enum _OELynxButton
{
    OELynxButtonUp,
    OELynxButtonDown,
    OELynxButtonLeft,
    OELynxButtonRight,
    OELynxButtonA,
    OELynxButtonB,
    OELynxButtonOption1,
    OELynxButtonOption2,
    OELynxButtonCount
} OELynxButton;

__attribute__((visibility("default")))
@interface MednafenGameCore : PVEmulatorCore

// Atari Lynx
- (oneway void)didPushLynxButton:(OELynxButton)button forPlayer:(NSUInteger)player;
- (oneway void)didReleaseLynxButton:(OELynxButton)button forPlayer:(NSUInteger)player;

// PC-*
- (oneway void)didPushPCEButton:(OEPCEButton)button forPlayer:(NSUInteger)player;
- (oneway void)didReleasePCEButton:(OEPCEButton)button forPlayer:(NSUInteger)player;
- (oneway void)didPushPCECDButton:(OEPCECDButton)button forPlayer:(NSUInteger)player;
- (oneway void)didReleasePCECDButton:(OEPCECDButton)button forPlayer:(NSUInteger)player;
- (oneway void)didPushPCFXButton:(OEPCFXButton)button forPlayer:(NSUInteger)player;
- (oneway void)didReleasePCFXButton:(OEPCFXButton)button forPlayer:(NSUInteger)player;

// PSX
- (oneway void)didPushPSXButton:(PVPSXButton)button forPlayer:(NSUInteger)player;
- (oneway void)didReleasePSXButton:(PVPSXButton)button forPlayer:(NSUInteger)player;
- (oneway void)didMovePSXJoystickDirection:(PVPSXButton)button withValue:(CGFloat)value forPlayer:(NSUInteger)player;

// Virtual Boy
- (oneway void)didPushVBButton:(OEVBButton)button forPlayer:(NSUInteger)player;
- (oneway void)didReleaseVBButton:(OEVBButton)button forPlayer:(NSUInteger)player;

// WonderSwan
- (oneway void)didPushWSButton:(OEWSButton)button forPlayer:(NSUInteger)player;
- (oneway void)didReleaseWSButton:(OEWSButton)button forPlayer:(NSUInteger)player;

@end
