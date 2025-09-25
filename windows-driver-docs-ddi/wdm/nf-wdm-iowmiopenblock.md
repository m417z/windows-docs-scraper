# IoWMIOpenBlock function

## Description

The **IoWMIOpenBlock** routine opens the WMI data block object for the specified WMI class.

## Parameters

### `Guid` [in]

Specifies the GUID for WMI class.

### `DesiredAccess` [in]

Specifies the desired access rights to the data block object. The caller must have particular access rights to perform certain operations.

The following is a description of each access right bit and the operations it allows:

#### WMIGUID_EXECUTE

The data block object can be used to run WMI class methods. This flag must be set to use [IoWMIExecuteMethod](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iowmiexecutemethod) on the data block object.

#### WMIGUID_NOTIFICATION

The data block object can be used to register event notification callbacks. This flag must be set to use [IoWMISetNotificationCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iowmisetnotificationcallback), and can only be used for WMI event blocks. Callers that specify this flag must also specify the SYNCHRONIZE flag.

#### WMIGUID_QUERY

The data block object can be used to query WMI class properties. This flag must be set to use any of the **IoWMIQuery*Xxx*** routines on the data block object.

#### WMIGUID_SET

The data block object can be used to set WMI class properties. This flag must be set to use any of the **IoWMISet*Xxx*** routines on the data block object.

### `DataBlockObject` [out]

Pointer to a memory location where the routine returns a pointer to the data block object.

## Return value

Returns STATUS_SUCCESS on success, or the appropriate NTSTATUS error code on failure.

## Remarks

The caller uses **IoWMIOpenBlock** to create a data block object for the specified WMI class GUID. Subsequently, the caller can use the data block object to read or write WMI class properties, run WMI class methods, and register callbacks for WMI events.

Use the **IoWMIQuery*Xxx*** and **IoWMISet*Xxx*** routines to read and write WMI class properties. Use [IoWMIExecuteMethod](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iowmiexecutemethod) to run WMI class methods, and use [IoWMISetNotificationCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iowmisetnotificationcallback) to register a WMI event notification callback.

Use [ObDereferenceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obdereferenceobject) to close the data block object once it is no longer needed.

## See also

[IoWMIExecuteMethod](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iowmiexecutemethod)

[IoWMIQueryAllData](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iowmiqueryalldata)

[IoWMIQueryAllDataMultiple](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iowmiqueryalldatamultiple)

[IoWMIQuerySingleInstance](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iowmiquerysingleinstance)

[IoWMIQuerySingleInstanceMultiple](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iowmiquerysingleinstancemultiple)

[IoWMISetNotificationCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iowmisetnotificationcallback)

[IoWMISetSingleInstance](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iowmisetsingleinstance)

[IoWMISetSingleItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iowmisetsingleitem)

[ZwClose](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntclose)