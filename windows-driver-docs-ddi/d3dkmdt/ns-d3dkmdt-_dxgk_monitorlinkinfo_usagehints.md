# DXGK_MONITORLINKINFO_USAGEHINTS structure

## Description

The **DXGK_MONITORLINKINFO_USAGEHINTS** structure provides hints to the driver on the intended usage of the display device (monitor).

## Members

### `Hidden`

When set, *DxgKrnl* will hide this display from Win32 so it cannot be a part of the desktop.

### `HeadMounted`

When set, the monitor is part of a head-mounted display (HMD) device.

### `Reserved`

This value is reserved for system use.

### `Value`

The collective value of the flags as a single value.