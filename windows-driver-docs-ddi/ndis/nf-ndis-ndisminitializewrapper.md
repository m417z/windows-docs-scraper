## Description

**Note** NDIS 5. *x* has been deprecated and is superseded by NDIS 6. *x*. For new NDIS driver development, see [Network Drivers Starting with Windows Vista](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/). For information about porting NDIS 5. *x* drivers to NDIS 6. *x*, see [Porting NDIS 5.x Drivers to NDIS 6.0](https://msdn.microsoft.com/library/Ff570059).

NdisMInitializeWrapper notifies NDIS that a new miniport driver is initializing.

## Parameters

### `_a` [out]

Pointer to a caller-supplied variable in which NDIS returns a handle that represents itself. If the call to **NdisMInitializeWrapper** fails, NDIS sets the variable at NdisWrapperHandle to **NULL**.

### `_b` [in]

Specifies a pointer of a system-specific type.

For Windows 2000 and later drivers, this is a pointer to an opaque driver object input to the miniport driver's **DriverEntry** function.

### `_c` [in]

Specifies a pointer of a system-specific type.

For Windows 2000 and later drivers, this is a pointer to an opaque registry path input to the miniport driver's **DriverEntry** function.

### `_d` [in]

Specifies a pointer of a system-specific type.

For Windows 2000 and later drivers, this pointer should be set to **NULL** when the miniport driver calls **NdisMInitializeWrapper**.

## Syntax

```cpp
VOID NdisInitializeWrapper(
  _Out_ PNDIS_HANDLE  NdisWrapperHandle,
  _In_ PVOID SystemSpecific1,
  _In_ PVOID SystemSpecific2,
  _In_ PVOID SystemSpecific3
);
```

## Remarks

A NIC driver or intermediate driver must call **NdisMInitializeWrapper** before it calls any other NdisXxx function. Usually, this call is the initial action of any NIC driver's **DriverEntry** function, which calls [**NdisMRegisterMiniport**](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff553602(v=vs.85)) or [**NdisIMRegisterLayeredMiniport**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisimregisterlayeredminiport) with the returned *NdisWrapperHandle* next. NDIS intermediate drivers also must call **NdisMInitializeWrapper** from the **DriverEntry** function and, then, call **NdisMRegisterMiniport** or **NdisIMRegisterLayeredMiniport** with the returned *NdisWrapperHandle*.

Such a driver's subsequent calls to *NdisXxx* initialization and configuration functions must pass the *NdisWrapperHandle* as a parameter. Consequently, it is an input parameter to the [**MiniportInitialize**](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff550472(v=vs.85)) function.

If the call to **NdisMInitializeWrapper** fails, NDIS sets the variable at *NdisWrapperHandle* to **NULL**. The driver should always check the value of this variable after **NdisMInitializeWrapper** returns. If the value is **NULL**, the driver should fail the call to the **DriverEntry** function.

## See also

[**Initializing a Miniport Driver**](https://learn.microsoft.com/windows-hardware/drivers/network/initializing-a-miniport-driver)

[**NdisMRegisterMiniport**](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff553602(v=vs.85))

[**MiniportInitialize**](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff550472(v=vs.85))

[**NdisIMRegisterLayeredMiniport**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisimregisterlayeredminiport)

[**NdisTerminateWrapper**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisterminatewrapper)