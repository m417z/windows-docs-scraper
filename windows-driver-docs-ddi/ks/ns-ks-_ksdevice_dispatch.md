# _KSDEVICE_DISPATCH structure

## Description

The KSDEVICE_DISPATCH structure describes the callbacks that a client can provide to receive notification of device creation and PnP events.

## Members

### `Add`

Optional. Can be **NULL**. A pointer to a minidriver-supplied [AVStrMiniDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnksdevicecreate) callback routine.

### `Start`

Optional. Can be **NULL**. A pointer to a minidriver-supplied [AVStrMiniDeviceStart](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnksdevicepnpstart) callback routine.

### `PostStart`

Optional. Can be **NULL**. A pointer to a minidriver-supplied [AVStrMiniDevicePostStart](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnksdevice) callback routine.

### `QueryStop`

Optional. Can be **NULL**. A pointer to a minidriver-supplied [AVStrMiniDeviceQueryStop](https://learn.microsoft.com/previous-versions/ff554299(v=vs.85)) callback routine.

### `CancelStop`

Optional. Can be **NULL**. A pointer to a minidriver-supplied [AVStrMiniDeviceCancelStop](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnksdeviceirpvoid) callback routine.

### `Stop`

Optional. Can be **NULL**. A pointer to a minidriver-supplied [AVStrMiniDeviceStop](https://learn.microsoft.com/previous-versions/ff556301(v=vs.85)) callback routine.

### `QueryRemove`

Optional. Can be **NULL**. A pointer to a minidriver-supplied [AVStrMiniDeviceQueryRemove](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnksdeviceirp) callback routine.

### `CancelRemove`

Optional. Can be **NULL**. A pointer to a minidriver-supplied [AVStrMiniDeviceCancelRemove](https://learn.microsoft.com/previous-versions/ff554278(v=vs.85)) callback routine.

### `Remove`

Optional. Can be **NULL**. A pointer to a minidriver-supplied [AVStrMiniDeviceRemove](https://learn.microsoft.com/previous-versions/ff554305(v=vs.85)) callback routine.

### `QueryCapabilities`

Optional. Can be **NULL**. A pointer to a minidriver-supplied [AVStrMiniDeviceQueryCapabilities](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnksdevicequerycapabilities) callback routine.

### `SurpriseRemoval`

Optional. Can be **NULL**. A pointer to a minidriver-supplied [AVStrMiniDeviceSurpriseRemoval](https://learn.microsoft.com/previous-versions/ff556304(v=vs.85)) callback routine.

### `QueryPower`

Optional. can be **NULL**. A pointer to a minidriver-supplied [AVStrMiniDeviceQueryPower](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnksdevicequerypower) callback routine.

### `SetPower`

Optional. Can be **NULL**. A pointer to a minidriver-supplied [AVStrMiniDeviceSetPower](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnksdevicesetpower) callback routine.

### `QueryInterface`

Optional. Can be **NULL**. A pointer to a minidriver-supplied [AVStrMiniDeviceQueryInterface](https://learn.microsoft.com/previous-versions/ff554290(v=vs.85)) callback routine.

## Remarks

In describing a device with the [KSDEVICE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksdevice_descriptor) structure, clients include a pointer to a dispatch table defined by this structure. Any member of this structure may be **NULL** indicating that the minidriver receives no notification for that particular message.

## See also

[KSDEVICE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksdevice_descriptor)