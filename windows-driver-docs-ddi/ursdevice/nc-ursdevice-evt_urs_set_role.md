# EVT_URS_SET_ROLE callback function

## Description

The URS class extension invokes this event callback when it requires the client driver to change the role of the controller.

## Parameters

### `Device` [in]

A handle to the framework device object that the client driver retrieved in the previous call to [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate).

### `Role` [in]

A [URS_ROLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/urstypes/ne-urstypes-_urs_role) type value that indicates the role to set for the controller device.

## Return value

If the operation is successful, the callback function must return STATUS_SUCCESS, or another status value for which NT_SUCCESS(status) equals TRUE. Otherwise it must return a status value for which NT_SUCCESS(status) equals FALSE.

## Remarks

 To register the client driver's implementation of the event callback the driver must set the **EvtUrsSetRole** member of [URS_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/ursdevice/ns-ursdevice-_urs_config) to a function pointer of the implementation method and then call the [UrsDeviceInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/ursdevice/nf-ursdevice-ursdeviceinitialize) method by passing the populated structure. The driver must call the method after it creates the framework device object for the controller.

#### Examples

```

NTSTATUS
EvtUrsSetRole (
    _In_ WDFDEVICE Device,
    _In_ URS_ROLE Role
    )
{
    NTSTATUS status;
    PFDO_CONTEXT fdoContext;

    TRACE_FUNC_ENTRY(TRACE_FLAG);
    TRY {

           // Change the current role of the controller to the specified role.
           // The driver might have stored the control registers in the device context.
           // Read and write the register to get and set the current role.

        }

        TRACE_INFO(TRACE_FLAG, "[Device: 0x%p] Successfully set role to %!URS_ROLE!", Device, Role);

        status = STATUS_SUCCESS;

    } FINALLY {

    }

    TRACE_FUNC_EXIT(TRACE_FLAG);

    return status;
}
```

## See also

[UrsDeviceInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/ursdevice/nf-ursdevice-ursdeviceinitialize)