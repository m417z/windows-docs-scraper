# WdfCmResourceListGetCount function

## Description

[Applies to KMDF and UMDF]

The **WdfCmResourceListGetCount** method returns the number of resource descriptors that are contained in a specified resource list.

## Parameters

### `List` [in]

A handle to a framework resource-list object that represents a list of hardware resources for a device.

## Return value

**WdfCmResourceListGetCount** returns the number of resource descriptors that are contained in the resource list that the *List* parameter specifies.

A system bug check occurs if the driver supplies an invalid object handle.

## Remarks

For more information about resource lists, see [Hardware Resources for Framework-Based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/hardware-resources-for-kmdf-drivers).

#### Examples

The following code example shows how an [EvtDevicePrepareHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_prepare_hardware) callback function might locate the memory, port, and interrupt resources in the list of [translated hardware resources](https://learn.microsoft.com/windows-hardware/drivers/wdf/raw-and-translated-resources) that the Plug and Play (PnP) manager has assigned to a device.

```cpp
NTSTATUS
MyEvtDevicePrepareHardware (
    WDFDEVICE  Device,
    WDFCMRESLIST  Resources,
    WDFCMRESLIST  ResourcesTranslated
    )
{
    ULONG  i;
    PCM_PARTIAL_RESOURCE_DESCRIPTOR  desc;

    for (i = 0; i < WdfCmResourceListGetCount(ResourcesTranslated); i++) {

        desc = WdfCmResourceListGetDescriptor(
                                              ResourcesTranslated,
                                              i
                                              );

        switch (desc->Type) {

            case CmResourceTypeMemory:
                //
                // Handle memory resources here.
                //
                break;

            case CmResourceTypePort:
                //
                // Handle port resources here.
                //
                break;

            case CmResourceTypeInterrupt:
                //
                // Handle interrupt resources here.
                //
                break;
            default:
                //
                // Ignore all other descriptors.
                //
                break;
        }
    }
}
```