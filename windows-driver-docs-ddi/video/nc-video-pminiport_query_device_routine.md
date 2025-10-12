# PMINIPORT_QUERY_DEVICE_ROUTINE callback function

## Description

*HwVidQueryDeviceCallback* uses the specified configuration data to configure its adapter, and, possibly, to fill in missing configuration information in the [VIDEO_PORT_CONFIG_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_port_config_info) structure.

## Parameters

### `HwDeviceExtension`

Pointer to the miniport driver's per-adapter storage area. For more information, see [Device Extensions](https://learn.microsoft.com/windows-hardware/drivers/kernel/device-extensions).

### `Context`

Pointer to the context value set up by [HwVidFindAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_find_adapter). Usually, it points to the VIDEO_PORT_CONFIG_INFO buffer or to an offset in that buffer.

### `DeviceDataType`

Specifies the type of configuration information that was requested, which is one of the following:

**VpBusData**

**VpCmosData**

**VpControllerData**

**VpMachineData**

**VpMonitorData**

Miniport drivers of x86-type video adapters usually specify **VpBusData**, particularly for adapters on EISA buses. The **VpControllerData** and **VpMonitorData** values have meaning only on ARC-compliant platforms. The **VpCmosData** and **VpMachineData** values are seldom used.

### `Identifier`

Pointer to the name of the device as determined by the ARC firmware. This parameter should be used only on ARC-compliant platforms. Otherwise, this pointer should be **NULL**.

### `IdentiferLength`

Specifies the size in bytes of the buffered *Identifier* string*.* The value should be zero if the machine is not ARC-compliant.

### `ConfigurationData`

Pointer to hardware configuration data. The format of this data is determined by the specified *DeviceDataType* and by the **AdapterInterfaceType** value in the VIDEO_PORT_CONFIG_INFO.

### `ConfigurationDataLength`

Specifies the size in bytes of the *ConfigurationData* buffer. In effect, this indicates how much information was collected from the registry and stored in the *ConfigurationData* buffer allocated by [VideoPortGetDeviceBase](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetdevicebase).

### `ComponentInformation`

Reserved for system use.

### `ComponentInformationLength`

Reserved for system use.

## Return value

*HwVidQueryDeviceCallback* returns the status of the operation.

## Remarks

*HwVidQueryDeviceCallback* is passed in a call to [VideoPortGetDeviceData](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetdevicedata) from the miniport driver's [HwVidFindAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_find_adapter) function. **VideoPortGetDeviceData** calls *HwVidQueryDeviceCallback* after collecting available configuration information under the **\Registry\Machine\Hardware\Description** node of the registry.

*HwVidQueryDeviceCallback* examines the *ConfigurationData*, collected from the registry by **VideoPortGetDeviceData**. It uses this information to configure its adapter, and, possibly, to fill in missing configuration information in the [VIDEO_PORT_CONFIG_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_port_config_info) structure.

*HwVidQueryDeviceCallback* cannot pass access range values found in the *ConfigurationData* to any **VideoPortRead***Xxx* or **VideoPortWrite***Xxx* directly; such addresses first must be mapped by calling [VideoPortGetDeviceBase](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetdevicebase).

If the *ConfigurationData* buffer has no access range information and the miniport driver's *HwVidFindAdapter* function has not already called [VideoPortGetBusData](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetbusdata) (or [VideoPortGetAccessRanges](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetaccessranges)), its *HwVidQueryDeviceCallback* function can call **VideoPortGetBusData**. Access range information returned by **VideoPortGetBusData** also must be passed to [VideoPortVerifyAccessRanges](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportverifyaccessranges).

If **VideoPortVerifyAccessRanges** returns NO_ERROR, the miniport driver can call **VideoPortGetDeviceBase** to obtain mapped logical addresses that it can use to communicate with the adapter by calling the **VideoPortRead***Xxx* and/or **VideoPortWrite***Xxx* functions.

If it cannot get bus-relative access ranges values by calling **VideoPortGetDeviceData**, **VideoPortGetBusData**, or **VideoPortGetAccessRanges**, a miniport driver can use a set of driver-supplied default access-range values to find its adapter. In these circumstances, the miniport driver must call **VideoPortVerifyAccessRanges** with the miniport driver-supplied access ranges, and, then call **VideoPortGetDeviceBase** only if **VideoPortVerifyAccessRanges** returned NO_ERROR. If a call to **VideoPortVerifyAccessRanges** is unsuccessful, a given bus-relative range is already in use by the driver of another device.

*HwVidQueryDeviceCallback* should be made pageable.

## See also

[VideoPortGetAccessRanges](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetaccessranges)

[VideoPortGetBusData](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetbusdata)

[VideoPortGetDeviceBase](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetdevicebase)

[VideoPortGetDeviceData](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetdevicedata)

[VideoPortVerifyAccessRanges](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportverifyaccessranges)