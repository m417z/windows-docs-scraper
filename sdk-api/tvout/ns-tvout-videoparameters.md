# VIDEOPARAMETERS structure

## Description

The video miniport driver receives a pointer to a VIDEOPARAMETERS structure in the **InputBuffer** member of a [VIDEO_REQUEST_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/video/ns-video-_video_request_packet) when the IOCTL request is [IOCTL_VIDEO_HANDLE_VIDEOPARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ntddvdeo/ni-ntddvdeo-ioctl_video_handle_videoparameters). Depending on the **dwCommand** member of the VIDEOPARAMETERS structure, the miniport driver should get or set the television connector and copy protection capabilities of the device.

## Members

### `Guid`

Specifies the globally unique identifier (GUID) for this structure {02C62061-1097-11d1-920F-00A024DF156E}. A video miniport driver must verify the GUID at the start of the structure before processing the structure.

### `dwOffset`

Is reserved and should be ignored by the video miniport driver.

### `dwCommand`

Indicates the action to be performed by the driver. This member can be one of the following values:

#### VP_COMMAND_GET

The miniport driver should return all of the device's TV connector capabilities, current TV connector settings, copy protection capabilities, and current copy protection settings by setting the appropriate flags in **dwFlags** and setting the values of the members that correspond to those set flags.

#### VP_COMMAND_SET

The miniport driver should set the TV connector and copy protection hardware according to the members of this structure that correspond to the flags set in **dwFlags**.

### `dwFlags`

Indicates which members of this structure contain valid data. When **dwCommand** is VP_COMMAND_GET, the driver should set the appropriate bits in this member to indicate in which corresponding members it has returned valid data. When **dwCommand** is VP_COMMAND_SET, the driver should set the functionality on the hardware according to values in the members that correspond with the bits set in this member. This member can be a bitwise OR of the values listed in the first column of the following table.

| Flag | Corresponding Members | Commands |
| --- | --- | --- |
| VP_FLAGS_BRIGHTNESS | **dwBrightness** | get/set |
| VP_FLAGS_CONTRAST | **dwContrast** | get/set |
| VP_FLAGS_COPYPROTECT | **dwCPType**<br><br>**dwCPCommand**<br><br>**dwCPStandard**<br><br>**dwCPKey**<br><br>**bCP_APSTriggerBits**<br><br>**bOEMCopyProtection** | get/set<br><br>set<br><br>get<br><br>set<br><br>set<br><br>get/set |
| VP_FLAGS_FLICKER | **dwFlickerFilter** | get/set |
| VP_FLAGS_MAX_UNSCALED | **dwMaxUnscaledX**<br><br>**dwMaxUnscaledY** | get<br><br>get |
| VP_FLAGS_OVERSCAN | **dwOverscanX**<br><br>**dwOverscanY** | get/set<br><br>get/set |
| VP_FLAGS_POSITION | **dwPositionX**<br><br>**dwPositionY** | get/set<br><br>get/set |
| VP_FLAGS_TV_MODE | **dwMode**<br><br>**dwAvailableModes** | get/set<br><br>get |
| VP_FLAGS_TV_STANDARD | **dwTVStandard**<br><br>**dwAvailableTVStandard** | get/set<br><br>get |

### `dwMode`

Specifies the current playback mode. This member is valid for both the VP_COMMAND_SET and VP_COMMAND_GET commands, and can be one of the following values:

#### VP_MODE_TV_PLAYBACK

Describes an optimal set of fields for video playback, with the flicker filter off and overscan display on.

#### VP_MODE_WIN_GRAPHICS

Describes the display settings that are optimal for Windows display, with the maximum flicker filter on and any overscan display off.

### `dwTVStandard`

Is the current world television standard. This member is valid for both the VP_COMMAND_SET and VP_COMMAND_GET commands, and can be one of the following values:

VP_TV_STANDARD_NTSC_M

VP_TV_STANDARD_NTSC_M_J

VP_TV_STANDARD_NTSC_433

VP_TV_STANDARD_PAL_B

VP_TV_STANDARD_PAL_D

VP_TV_STANDARD_PAL_G

VP_TV_STANDARD_PAL_H

VP_TV_STANDARD_PAL_I

VP_TV_STANDARD_PAL_M

VP_TV_STANDARD_PAL_N

VP_TV_STANDARD_PAL_60

VP_TV_STANDARD_SECAM_B

VP_TV_STANDARD_SECAM_D

VP_TV_STANDARD_SECAM_G

VP_TV_STANDARD_SECAM_H

VP_TV_STANDARD_SECAM_K

VP_TV_STANDARD_SECAM_K1

VP_TV_STANDARD_SECAM_L

VP_TV_STANDARD_SECAM_L1

VP_TV_STANDARD_WIN_VGA

### `dwAvailableModes`

Indicates the playback modes the device is capable of. This member is only valid for the VP_COMMAND_GET command, and can be a bitwise OR of the following values:

VP_MODE_TV_PLAYBACK

VP_MODE_WIN_GRAPHICS

### `dwAvailableTVStandard`

Specifies all available world television standards. This member is only valid for the VP_COMMAND_GET command, and can be a bitwise OR of the following values:

VP_TV_STANDARD_NTSC_M

VP_TV_STANDARD_NTSC_M_J

VP_TV_STANDARD_NTSC_433

VP_TV_STANDARD_PAL_B

VP_TV_STANDARD_PAL_D

VP_TV_STANDARD_PAL_G

VP_TV_STANDARD_PAL_H

VP_TV_STANDARD_PAL_I

VP_TV_STANDARD_PAL_M

VP_TV_STANDARD_PAL_N

VP_TV_STANDARD_PAL_60

VP_TV_STANDARD_SECAM_B

VP_TV_STANDARD_SECAM_D

VP_TV_STANDARD_SECAM_G

VP_TV_STANDARD_SECAM_H

VP_TV_STANDARD_SECAM_K

VP_TV_STANDARD_SECAM_K1

VP_TV_STANDARD_SECAM_L

VP_TV_STANDARD_SECAM_L1

VP_TV_STANDARD_WIN_VGA

### `dwFlickerFilter`

Is a value in tenths of a percent that indicates the flicker filter state. This member can be a value between [0,1000], and is valid for both VP_COMMAND_GET and VP_COMMAND_SET.

### `dwOverScanX`

Is a value in tenths of a percent that indicates the amount of overscan in *x*. This member can be a value between [0,1000], and is valid for both VP_COMMAND_GET and VP_COMMAND_SET.

### `dwOverScanY`

Is a value in tenths of a percent that indicates the amount of overscan in *y*. This member can be a value between [0,1000], and is valid for both VP_COMMAND_GET and VP_COMMAND_SET.

### `dwMaxUnscaledX`

Is the maximum *x* resolution that the TV can display without having the hardware scale the video image. The miniport driver must set a value in this member when **dwCommand** is VP_COMMAND_GET. This member is invalid for VP_COMMAND_SET.

### `dwMaxUnscaledY`

Is the maximum *y* resolution that the TV can display without having the hardware scale the video image. The miniport driver must set a value in this member when **dwCommand** is VP_COMMAND_GET. This member is invalid for VP_COMMAND_SET.

### `dwPositionX`

Is the value used by the hardware to determine the current *x* position of the image on the TV. This member is specified in pixels, and is valid for both VP_COMMAND_GET and VP_COMMAND_SET.

### `dwPositionY`

Is the value used by the hardware to determine the current *y* position of the image on the TV. This member is specified in scan lines, and is valid for both VP_COMMAND_GET and VP_COMMAND_SET.

### `dwBrightness`

Is a percentage value that indicates the brightness setting on the TV. This member can be a value between [0,100], and is valid for both VP_COMMAND_GET and VP_COMMAND_SET.

### `dwContrast`

Is a percentage value that indicates the contrast setting on the TV. This member can be a value between [0,100], and is valid for both VP_COMMAND_GET and VP_COMMAND_SET.

### `dwCPType`

Specifies the type of copy protection supported by the device. This member is valid for both the VP_COMMAND_SET and VP_COMMAND_GET commands, and can be CP_TYPE_APS_TRIGGER.

### `dwCPCommand`

Is the copy protection command. This member is only valid for the VP_COMMAND_SET command, and can be one of the following values:

#### VP_CP_CMD_ACTIVATE

The miniport driver should turn on copy protection and generate and return a unique copy protection key in **dwCPKey**.

#### VP_CP_CMD_CHANGE

If the copy protection key in **dwCPKey** is valid, the miniport driver should change copy protection based on the trigger data in **bCP_APSTriggerBits**.

#### VP_CP_CMD_DEACTIVATE

If the copy protection key in **dwCPKey** is valid, the miniport driver should turn off copy protection.

### `dwCPStandard`

Is the TV standards for which copy protection types are available. This member is only valid for the VP_COMMAND_GET command, and can be a bitwise OR of the following values:

VP_TV_STANDARD_NTSC_M

VP_TV_STANDARD_NTSC_M_J

VP_TV_STANDARD_NTSC_433

VP_TV_STANDARD_PAL_B

VP_TV_STANDARD_PAL_D

VP_TV_STANDARD_PAL_G

VP_TV_STANDARD_PAL_H

VP_TV_STANDARD_PAL_I

VP_TV_STANDARD_PAL_M

VP_TV_STANDARD_PAL_N

VP_TV_STANDARD_PAL_60

VP_TV_STANDARD_SECAM_B

VP_TV_STANDARD_SECAM_D

VP_TV_STANDARD_SECAM_G

VP_TV_STANDARD_SECAM_H

VP_TV_STANDARD_SECAM_K

VP_TV_STANDARD_SECAM_K1

VP_TV_STANDARD_SECAM_L

VP_TV_STANDARD_SECAM_L1

VP_TV_STANDARD_WIN_VGA

### `dwCPKey`

Is a driver-generated copy protection key that is unique to this instance of the driver. This member is valid only for the VP_COMMAND_SET command. The miniport driver generates and returns this key when **dwCPCommand** is set to VP_CP_CMD_ACTIVATE. The caller must set this key when the **dwCPCommand** field is either VP_CP_CMD_DEACTIVATE or VP_CP_CMD_CHANGE. If the caller sets an incorrect key, the driver must not change the current copy protection settings.

### `bCP_APSTriggerBits`

Specifies DVD analog protection system (APS) trigger bit data. Bits zero and 1 are valid. This member is valid only for the VP_COMMAND_SET command.

### `bOEMCopyProtection`

OEM-specific copy protection data. This member is valid for both the VP_COMMAND_SET and VP_COMMAND_GET commands.

## See also

[IOCTL_VIDEO_HANDLE_VIDEOPARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ntddvdeo/ni-ntddvdeo-ioctl_video_handle_videoparameters)

[VIDEO_REQUEST_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/video/ns-video-_video_request_packet)