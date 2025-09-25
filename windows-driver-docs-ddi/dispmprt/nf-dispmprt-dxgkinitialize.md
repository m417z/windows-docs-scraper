# DxgkInitialize function

## Description

A kernel-mode display miniport driver's (KMD) [**DriverEntry**](https://learn.microsoft.com/windows-hardware/drivers/display/driverentry-of-display-miniport-driver) routine calls the system-supplied **DxgkInitialize** function to load and initialize the DirectX graphics kernel subsystem (*Dxgkrnl.sys*).

## Parameters

### `DriverObject` [in]

Pointer to a [**DRIVER_OBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_driver_object) structure. The OS passed **DriverObject** to the KMD when it calls KMD's [**DriverEntry**](https://learn.microsoft.com/windows-hardware/drivers/display/driverentry-of-display-miniport-driver) routine.

### `RegistryPath` [in]

Pointer to a [**UNICODE_STRING**](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) that supplies the path to the driver's service registry key. The OS passes **RegistryPath** to KMD when it calls KMD's [**DriverEntry**](https://learn.microsoft.com/windows-hardware/drivers/display/driverentry-of-display-miniport-driver) routine.

### `DriverInitializationData` [in]

Pointer to a [**DRIVER_INITIALIZATION_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_driver_initialization_data) structure that supplies *Dxgkrnl* with pointers to functions implemented by the KMD.

## Return value

**DxgkInitialize** returns STATUS_SUCCESS if it succeeds; otherwise, it returns one of the error codes defined in *Ntstatus.h*.

## Remarks

The following code example shows an implementation of [**DriverEntry**](https://learn.microsoft.com/windows-hardware/drivers/display/driverentry-of-display-miniport-driver) in which **DxgkInitialize** is called.

```cpp
NTSTATUS
DriverEntry(
    IN PDRIVER_OBJECT DriverObject,
    IN PUNICODE_STRING RegistryPath
    )
{
    DRIVER_INITIALIZATION_DATA DriverInitializationData = {'\0'};

    PAGED_CODE();

    if (! ARGUMENT_PRESENT(DriverObject) ||
        ! ARGUMENT_PRESENT(RegistryPath))
    {
        return STATUS_INVALID_PARAMETER;
    }

    // Fill in the DriverInitializationData structure and call DxgkInitialize()
    DriverInitializationData.Version  = DXGKDDI_INTERFACE_VERSION;

    DriverInitializationData.DxgkDdiAddDevice  = MyKMDAddDevice;
    DriverInitializationData.DxgkDdiStartDevice  = MyKMDStartDevice;
    DriverInitializationData.DxgkDdiStopDevice  = MyKMDStopDevice;
    DriverInitializationData.DxgkDdiRemoveDevice  = MyKMDRemoveDevice;
    DriverInitializationData.DxgkDdiDispatchIoRequest  = MyKMDDispatchIoRequest;
    DriverInitializationData.DxgkDdiInterruptRoutine  = MyKMDInterruptRoutine;
    DriverInitializationData.DxgkDdiDpcRoutine  = MyKMDDpcRoutine;
    DriverInitializationData.DxgkDdiQueryChildRelations  = MyKMDQueryChildRelations;
    DriverInitializationData.DxgkDdiQueryChildStatus   = MyKMDQueryChildStatus;
    DriverInitializationData.DxgkDdiQueryDeviceDescriptor  = MyKMDQueryDeviceDescriptor;
    DriverInitializationData.DxgkDdiSetPowerState  = MyKMDSetPowerState;
    DriverInitializationData.DxgkDdiNotifyAcpiEvent  = MyKMDNotifyAcpiEvent;
    DriverInitializationData.DxgkDdiResetDevice  = MyKMDResetDevice;
    DriverInitializationData.DxgkDdiUnload  = MyKMDUnload;
    DriverInitializationData.DxgkDdiQueryInterface  = MyKMDQueryInterface;
    DriverInitializationData.DxgkDdiControlEtwLogging  = MyKMDControlEtwLogging;

    DriverInitializationData.DxgkDdiQueryAdapterInfo  = MyKMDQueryAdapterInfo;
    DriverInitializationData.DxgkDdiCreateDevice  = MyKMDCreateDevice;
    DriverInitializationData.DxgkDdiCreateAllocation  = MyKMDCreateAllocation;
    DriverInitializationData.DxgkDdiDestroyAllocation  = MyKMDDestroyAllocation;

    DriverInitializationData.DxgkDdiCreateOverlay  = MyKMDCreateOverlay;
    DriverInitializationData.DxgkDdiUpdateOverlay  = MyKMDUpdateOverlay;
    DriverInitializationData.DxgkDdiFlipOverlay  = MyKMDFlipOverlay;
    DriverInitializationData.DxgkDdiDestroyOverlay  = MyKMDDestroyOverlay;

    DriverInitializationData.DxgkDdiDescribeAllocation  = MyKMDDescribeAllocation;
    DriverInitializationData.DxgkDdiGetStandardAllocationDriverData = MyKMDGetStandardAllocationDriverData;

    DriverInitializationData.DxgkDdiAcquireSwizzlingRange  = MyKMDAcquireSwizzlingRange;
    DriverInitializationData.DxgkDdiReleaseSwizzlingRange  = MyKMDReleaseSwizzlingRange;

    DriverInitializationData.DxgkDdiOpenAllocation  = MyKMDOpenAllocation;
    DriverInitializationData.DxgkDdiCloseAllocation  = MyKMDCloseAllocation;

    DriverInitializationData.DxgkDdiPatch  = MyKMDPatchDmaBuffer;
    DriverInitializationData.DxgkDdiSubmitCommand  = MyKMDSubmitCommand;
    DriverInitializationData.DxgkDdiBuildPagingBuffer  = MyKMDBuildPagingBuffer;
    DriverInitializationData.DxgkDdiSetPalette  = MyKMDSetPalette;
    DriverInitializationData.DxgkDdiSetPointerShape  = MyKMDSetPointerShape;
    DriverInitializationData.DxgkDdiSetPointerPosition  = MyKMDSetPointerPosition;
    DriverInitializationData.DxgkDdiPreemptCommand  = MyKMDPreemptCommand;

    DriverInitializationData.DxgkDdiDestroyDevice  = MyKMDDestroyDevice;
    DriverInitializationData.DxgkDdiRender  = MyKMDRender;
    DriverInitializationData.DxgkDdiRenderKm  = MyKMDRenderKm;    DriverInitializationData.DxgkDdiPresent  = MyKMDPresent;
    DriverInitializationData.DxgkDdiResetFromTimeout  = MyKMDResetFromTimeout;
    DriverInitializationData.DxgkDdiRestartFromTimeout  = MyKMDRestartFromTimeout;
    DriverInitializationData.DxgkDdiEscape  = MyKMDEscape;
    DriverInitializationData.DxgkDdiCollectDbgInfo  = MyKMDCollectDbgInfo;
    DriverInitializationData.DxgkDdiQueryCurrentFence  = MyKMDQueryCurrentFence;
    DriverInitializationData.DxgkDdiControlInterrupt  = MyKMDControlInterrupt;
    DriverInitializationData.DxgkDdiGetScanLine  = MyKMDGetScanLine;
    DriverInitializationData.DxgkDdiStopCapture  = MyKMD DxgkDdiStopCapture;    DriverInitializationData.DxgkDdiSetVidPnSourceAddress  = MyKMDSetVidPnSourceAddress;
    DriverInitializationData.DxgkDdiSetVidPnSourceVisibility  = MyKMDSetVidPnSourceVisibility;
    DriverInitializationData.DxgkDdiUpdateActiveVidPnPresentPath  = MyKMDUpdateActiveVidPnPresentPath;
    DriverInitializationData.DxgkDdiCommitVidPn  = MyKMDCommitVidPn;
    DriverInitializationData.DxgkDdiRecommendMonitorModes  = MyKMDRecommendMonitorModes;
    DriverInitializationData.DxgkDdiRecommendVidPnTopology  = MyKMDRecommendVidPnTopology;

    DriverInitializationData.DxgkDdiCreateContext  = MyKMDCreateContext;
    DriverInitializationData.DxgkDdiDestroyContext  = MyKMDDestroyContext;

    DriverInitializationData.DxgkDdiLinkDevice  = MyKMDLinkDevice;
    DriverInitializationData.DxgkDdiSetDisplayPrivateDriverFormat  = MyKMDSetDisplayPrivateDriverFormat;
    DriverInitializationData.DxgkDdiRecommendFunctionalVidPn  = MyKMDRecommendFunctionalVidPn_XddmParity;
    DriverInitializationData.DxgkDdiEnumVidPnCofuncModality  = MyKMDEnumVidPnCofuncModality_XddmParity;
    DriverInitializationData.DxgkDdiIsSupportedVidPn  = MyKMDIsSupportedVidPn_XddmParity;
    DriverInitializationData.DxgkDdiQueryVidPnHWCapability  = MyKMD DxgkDdiQueryVidPnHWCapability;

    return DxgkInitialize(DriverObject,
                          RegistryPath,
                          &DriverInitializationData);
}
```

## See also

[**DRIVER_INITIALIZATION_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_driver_initialization_data)

[**DRIVER_OBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_driver_object)

[**DriverEntry of Display Miniport Driver**](https://learn.microsoft.com/windows-hardware/drivers/display/driverentry-of-display-miniport-driver)

[**UNICODE_STRING**](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)