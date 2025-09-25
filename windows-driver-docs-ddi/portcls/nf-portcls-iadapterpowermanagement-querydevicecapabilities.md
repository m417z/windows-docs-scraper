# IAdapterPowerManagement::QueryDeviceCapabilities

## Description

The `QueryDeviceCapabilities` method is called by PortCls in response to a Plug and Play [IRP_MN_QUERY_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-capabilities) IRP.

## Parameters

### `PowerDeviceCaps` [in]

Pointer to a [DEVICE_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_capabilities) structure specifying the device's capabilities

## Return value

`QueryDeviceCapabilities` returns STATUS_SUCCESS if call was successful. Otherwise, the method returns an appropriate error code.

## Remarks

This method is called at driver startup to get the capabilities for the device. The method passes to the adapter driver a capabilities structure that defines the mappings between system power states and device power states. PortCls writes the default values for these mappings into the structure before calling the method. During the call, the adapter driver has the opportunity to edit the mappings, if necessary.

Typically, the adapter driver should not change these settings. If the adapter driver must override the defaults, it can change the mappings to a deeper (less-powered) device power state but not to a weaker (more-powered) device power state. For example, the mappings for S1 (PowerSystemSleeping1) can be changed from D1 to D3, but not to D0.

In order to fill in the *PowerDeviceCaps* structure for a device, the adapter driver should call [PcRegisterAdapterPowerManagement](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-pcregisteradapterpowermanagement) to register the **IAdapterPowerManagement** interface at device-startup time. The operating system queries devices before calling the adapter driver's device-startup routine.

In order to change the mappings between system power states and device power states, the adapter driver changes the values in the **DeviceState** array in the *PowerDeviceCaps* structure. These mappings should be changed only if necessary. The following code example shows how to map D1 mappings to D3:

```
  for (i=ULONG(PowerSystemWorking); i<=ULONG(PowerSystemShutdown); i++)
      {
          if (PowerDeviceCaps->DeviceState[i] == PowerDeviceD1)
          {
              PowerDeviceCaps->DeviceState[i] = PowerDeviceD3;
          }
      }
```

The code for the `QueryDeviceCapabilities` method must reside in paged memory.

## See also

[DEVICE_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_capabilities)

[IAdapterPowerManagement](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iadapterpowermanagement)

[IRP_MN_QUERY_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-capabilities)

[PcRegisterAdapterPowerManagement](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-pcregisteradapterpowermanagement)