# DISPLAYCONFIG_SUPPORT_VIRTUAL_RESOLUTION structure

## Description

The DISPLAYCONFIG_SUPPORT_VIRTUAL_RESOLUTION structure contains information on the state of virtual resolution support for the monitor.

## Members

### `header`

A [DISPLAYCONFIG_DEVICE_INFO_HEADER](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-displayconfig_device_info_header) structure that holds information on the type, size, adapterID, and ID of the target the monitor is connected to.

### `DUMMYSTRUCTNAME`

### `DUMMYSTRUCTNAME.DUMMYSTRUCTNAME`

### `DUMMYSTRUCTNAME.DUMMYSTRUCTNAME.disableMonitorVirtualResolution`

Setting this bit disables virtual mode for the monitor using information found in **header**.

### `DUMMYSTRUCTNAME.DUMMYSTRUCTNAME.reserved`

Reserved for system use. Do not use in your driver.

### `DUMMYSTRUCTNAME.value`

Reflects the value of **disableMonitorVirtualResolution** in cases where debugging is utilized.