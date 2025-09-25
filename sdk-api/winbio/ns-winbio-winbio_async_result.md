# WINBIO_ASYNC_RESULT structure

## Description

The **WINBIO_ASYNC_RESULT** structure contains the results of an asynchronous operation.

## Members

### `SessionHandle`

Handle of an asynchronous session started by calling the [WinBioAsyncOpenSession](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioasyncopensession) function or the [WinBioAsyncOpenFramework](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioasyncopenframework) function.

### `Operation`

Type of the asynchronous operation. For more information, see [WINBIO_OPERATION_TYPE Constants](https://learn.microsoft.com/windows/desktop/SecBioMet/winbio-operation-type-constants).

### `SequenceNumber`

Sequence number of the asynchronous operation. The integers are assigned sequentially for each operation in a biometric session, starting at one (1). For any session, the open operation is always assigned the first sequence number and the close operation is assigned the last sequence number. If your application queues multiple operations, you can use sequence numbers to perform error handling. For example, you can ignore operation results until a specific sequence number is sent to the application.

### `TimeStamp`

System date and time at which the biometric operation began. For more information, see the **GetSystemTimeAsFileTime** function.

### `ApiStatus`

Error code returned by the operation.

### `UnitId`

The numeric unit identifier of the biometric unit that performed the operation.

### `UserData`

Address of an optional buffer supplied by the caller. The buffer is not modified by the framework or the biometric unit. Your application can use the data to help it determine what actions to perform upon receipt of the completion notice or to maintain additional information about the requested operation.

### `Parameters`

Union that encloses nested structures that contain additional information about the success or failure of asynchronous operations begun by the client application.

### `Parameters.Verify`

Contains the results of an asynchronous call to [WinBioVerify](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioverify).

### `Parameters.Verify.Match`

Specifies whether the captured sample matched the user identity.

### `Parameters.Verify.RejectDetail`

Additional information about verification failure. For more information, see Remarks.

### `Parameters.Identify`

Contains the results of an asynchronous call to [WinBioIdentify](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioidentify).

### `Parameters.Identify.Identity`

GUID or SID of the user providing the biometric sample.

### `Parameters.Identify.SubFactor`

Sub-factor associated with the biometric sample. For more information, see Remarks.

### `Parameters.Identify.RejectDetail`

Additional information about the failure, if any, to capture and identify a biometric sample. For more information, see Remarks.

### `Parameters.EnrollBegin`

Contains the results of an asynchronous call to [WinBioEnrollBegin](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioenrollbegin).

### `Parameters.EnrollBegin.SubFactor`

Additional information about the enrollment. For more information, see Remarks.

### `Parameters.EnrollCapture`

Contains the results of an asynchronous call to [WinBioEnrollCapture](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioenrollcapture).

### `Parameters.EnrollCapture.RejectDetail`

Additional information about the failure to capture a biometric sample. For more information, see Remarks.

### `Parameters.EnrollCommit`

Contains the results of an asynchronous call to [WinBioEnrollCommit](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioenrollcommit).

### `Parameters.EnrollCommit.Identity`

GUID or SID of the template to be saved.

### `Parameters.EnrollCommit.IsNewTemplate`

Specifies whether the template being added to the database is new.

### `Parameters.EnumEnrollments`

Contains the results of an asynchronous call to [WinBioEnumEnrollments](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioenumenrollments).

### `Parameters.EnumEnrollments.Identity`

GUID or SID of the template from which the sub-factors were retrieved.

### `Parameters.EnumEnrollments.SubFactorCount`

Number of elements in the array pointed to by the **SubFactorArray** member.

### `Parameters.EnumEnrollments.SubFactorArray`

Pointer to an array of sub-factors. For more information, see Remarks.

### `Parameters.CaptureSample`

Contains the results of an asynchronous call to [WinBioCaptureSample](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiocapturesample).

### `Parameters.CaptureSample.Sample`

Pointer to a [WINBIO_BIR](https://learn.microsoft.com/windows/desktop/SecBioMet/winbio-bir) structure that contains the sample.

### `Parameters.CaptureSample.SampleSize`

Size, in bytes, of the [WINBIO_BIR](https://learn.microsoft.com/windows/desktop/SecBioMet/winbio-bir) structure returned in the **Sample** member.

### `Parameters.CaptureSample.RejectDetail`

Additional information about the failure to capture a biometric sample. For more information, see Remarks.

### `Parameters.DeleteTemplate`

Contains the results of an asynchronous call to [WinBioDeleteTemplate](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiodeletetemplate).

### `Parameters.DeleteTemplate.Identity`

GUID or SID of the template that was deleted.

### `Parameters.DeleteTemplate.SubFactor`

Additional information about the template.

### `Parameters.GetProperty`

Contains the results of an asynchronous call to [WinBioGetProperty](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiogetproperty).

### `Parameters.GetProperty.PropertyType`

Source of the property information. Currently this will be **WINBIO_PROPERTY_TYPE_UNIT**.

### `Parameters.GetProperty.PropertyId`

The property that was queried. Currently this will be **WINBIO_PROPERTY_SAMPLE_HINT**.

### `Parameters.GetProperty.Identity`

This is a reserved value and will be **NULL**.

### `Parameters.GetProperty.SubFactor`

This is reserved and will be **WINBIO_SUBTYPE_NO_INFORMATION**.

### `Parameters.GetProperty.PropertyBufferSize`

Size, in bytes, of the property value pointed to by the **PropertyBuffer** member.

### `Parameters.GetProperty.PropertyBuffer`

Pointer to the property value.

### `Parameters.SetProperty`

Contains the results of an asynchronous call to [WinBioSetProperty](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiosetproperty). This member is supported starting in Windows 10.

##### SetProperty.PropretyBufferSize

The size, in bytes, of the structure to which the *PropertyBuffer* parameter points.

### `Parameters.SetProperty.PropertyType`

A **WINBIO_PROPERTY_TYPE** value that specifies the type of the property that was set. Currently this can only be **WINBIO_PROPERTY_TYPE_ACCOUNT**.

### `Parameters.SetProperty.PropertyId`

A **WINBIO_PROPERTY_ID** value that specifies the property that was set. Currently this value can only be **WINBIO_PROPERTY_ANTI_SPOOF_POLICY**. All other properties are read-only.

### `Parameters.SetProperty.Identity`

A [WINBIO_IDENTITY](https://learn.microsoft.com/windows/desktop/SecBioMet/winbio-identity) structure that specifies the account for which the property was set.

### `Parameters.SetProperty.SubFactor`

Reserved. Currently, this value will always be **WINBIO_SUBTYPE_NO_INFORMATION**.

### `Parameters.SetProperty.PropertyBufferSize`

### `Parameters.SetProperty.PropertyBuffer`

A pointer to a structure that specifies the value to which the property was set. For the **WINBIO_PROPERTY_ANTI_SPOOF_POLICY** property, the structure is a [WINBIO_ANTI_SPOOF_POLICY](https://learn.microsoft.com/windows/desktop/SecBioMet/winbio-anti-spoof-policy) structure.

### `Parameters.GetEvent`

Contains status information about the event that was raised.

### `Parameters.GetEvent.Event`

Contains event information.

### `Parameters.ControlUnit`

Contains the results of an asynchronous call to [WinBioControlUnit](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiocontrolunit) or [WinBioControlUnitPrivileged](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiocontrolunitprivileged).

### `Parameters.ControlUnit.Component`

The component within the biometric unit that performed the operation.

### `Parameters.ControlUnit.ControlCode`

Vendor-defined code recognized by the biometric unit specified by the *UnitId* parameter of the [WinBioControlUnit](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiocontrolunit) or [WinBioControlUnitPrivileged](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiocontrolunitprivileged) function and the adapter specified by the *Component* parameter.

### `Parameters.ControlUnit.OperationStatus`

Vendor-defined status code that specifies the outcome of the control operation.

### `Parameters.ControlUnit.SendBuffer`

Pointer to a buffer that contains the control information sent to the adapter by the component. The format and content of the buffer is vendor-defined.

### `Parameters.ControlUnit.SendBufferSize`

Size, in bytes, of the buffer specified by the **SendBuffer** member.

### `Parameters.ControlUnit.ReceiveBuffer`

Pointer to a buffer that receives information sent by the adapter specified by the **Component** member. The format and content of the buffer is vendor-defined.

### `Parameters.ControlUnit.ReceiveBufferSize`

Size, in bytes, of the buffer specified by the **ReceiveBuffer** member.

### `Parameters.ControlUnit.ReceiveDataSize`

Size, in bytes, of the data written to the buffer specified by the **ReceiveBuffer** member.

### `Parameters.EnumServiceProviders`

Contains the results of an asynchronous call to [WinBioEnumServiceProviders](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioenumserviceproviders) or [WinBioAsyncEnumServiceProviders](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioasyncenumserviceproviders).

### `Parameters.EnumServiceProviders.BspCount`

The number of structures pointed to by the **BspSchemaArray** member.

### `Parameters.EnumServiceProviders.BspSchemaArray`

Pointer to an array of [WINBIO_BSP_SCHEMA](https://learn.microsoft.com/windows/desktop/SecBioMet/winbio-bsp-schema) structures that contain information about each of the available service providers.

### `Parameters.EnumBiometricUnits`

Contains the results of an asynchronous call to [WinBioEnumBiometricUnits](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioenumbiometricunits) or [WinBioAsyncEnumBiometricUnits](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioasyncenumbiometricunits).

### `Parameters.EnumBiometricUnits.UnitCount`

Number of structures pointed to by the **UnitSchemaArray** member.

### `Parameters.EnumBiometricUnits.UnitSchemaArray`

An array of [WINBIO_UNIT_SCHEMA](https://learn.microsoft.com/windows/desktop/SecBioMet/winbio-unit-schema) structures that contain information about each enumerated biometric unit.

### `Parameters.EnumDatabases`

Contains the results of an asynchronous call to [WinBioEnumDatabases](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioenumdatabases) or [WinBioAsyncEnumDatabases](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioasyncenumdatabases).

### `Parameters.EnumDatabases.StorageCount`

Number of structures pointed to by the **StorageSchemaArray** member.

### `Parameters.EnumDatabases.StorageSchemaArray`

Array of [WINBIO_STORAGE_SCHEMA](https://learn.microsoft.com/windows/desktop/SecBioMet/winbio-storage-schema) structures that contain information about each database.

### `Parameters.VerifyAndReleaseTicket`

Reserved. This member is supported starting in Windows 10.

### `Parameters.VerifyAndReleaseTicket.Match`

Reserved.

### `Parameters.VerifyAndReleaseTicket.RejectDetail`

Reserved.

### `Parameters.VerifyAndReleaseTicket.Ticket`

Reserved.

### `Parameters.IdentifyAndReleaseTicket`

Reserved. This member is supported starting in Windows 10.

### `Parameters.IdentifyAndReleaseTicket.Identity`

Reserved.

### `Parameters.IdentifyAndReleaseTicket.SubFactor`

Reserved.

### `Parameters.IdentifyAndReleaseTicket.RejectDetail`

Reserved.

### `Parameters.IdentifyAndReleaseTicket.Ticket`

Reserved.

### `Parameters.EnrollSelect`

Contains the results of an asynchronous call to [WinBioEnrollSelect](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioenrollselect). This member is supported starting in Windows 10.

### `Parameters.EnrollSelect.SelectorValue`

A value that identifies that individual that was selected for enrollment.

### `Parameters.MonitorPresence`

Contains the results of an asynchronous call to [WinBioMonitorPresence](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiomonitorpresence). This member is supported starting in Windows 10.

### `Parameters.MonitorPresence.ChangeType`

A **WINBIO_PRESENCE_CHANGE** value that indicates the type of event that occurred.

### `Parameters.MonitorPresence.PresenceCount`

The size of the array that the **MonitorPresence.PresenceArray** member points to.

### `Parameters.MonitorPresence.PresenceArray`

Address of the array of [WINBIO_PRESENCE](https://learn.microsoft.com/windows/desktop/SecBioMet/winbio-presence) structures, one for each individual monitored.

### `Parameters.GetProtectionPolicy`

### `Parameters.GetProtectionPolicy.Identity`

### `Parameters.GetProtectionPolicy.Policy`

### `Parameters.NotifyUnitStatusChange`

### `Parameters.NotifyUnitStatusChange.ExtendedStatus`

## Remarks

Asynchronous operations are begun by opening a biometric session or a framework session. Call [WinBioAsyncOpenSession](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioasyncopensession) to open a biometric session. Call [WinBioAsyncOpenFramework](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioasyncopenframework) to open a framework session.

You can use an asynchronous biometric session handle to call any of the following operations asynchronously:

* [WinBioCancel](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiocancel)
* [WinBioCaptureSample](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiocapturesample)
* [WinBioCloseSession](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioclosesession)
* [WinBioControlUnit](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiocontrolunit)
* [WinBioControlUnitPrivileged](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiocontrolunitprivileged)
* [WinBioDeleteTemplate](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiodeletetemplate)
* [WinBioEnrollBegin](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioenrollbegin)
* [WinBioEnrollCapture](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioenrollcapture)
* [WinBioEnrollCommit](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioenrollcommit)
* [WinBioEnrollDiscard](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioenrolldiscard)
* [WinBioEnumEnrollments](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioenumenrollments)
* [WinBioGetProperty](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiogetproperty)
* [WinBioIdentify](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioidentify)
* [WinBioLocateSensor](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiolocatesensor)
* [WinBioLockUnit](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiolockunit)
* [WinBioLogonIdentifiedUser](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiologonidentifieduser)
* [WinBioRegisterEventMonitor](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioregistereventmonitor)
* [WinBioUnlockUnit](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiounlockunit)
* [WinBioUnregisterEventMonitor](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiounregistereventmonitor)
* [WinBioVerify](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioverify)
* [WinBioWait](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiowait)
* [WinBioSetProperty](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiosetproperty)
* [WinBioEnrollSelect](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioenrollselect)
* [WinBioMonitorPresence](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiomonitorpresence)

You can use an asynchronous framework handle to call the following operations asynchronously:

* [WinBioAsyncEnumBiometricUnits](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioasyncenumbiometricunits)
* [WinBioAsyncEnumDatabases](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioasyncenumdatabases)
* [WinBioAsyncOpenFramework](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioasyncopenframework)
* [WinBioAsyncEnumServiceProviders](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioasyncenumserviceproviders)
* [WinBioAsyncMonitorFrameworkChanges](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioasyncmonitorframeworkchanges)

The **WINBIO_ASYNC_RESULT** structure is allocated internally by the Windows Biometric Framework. Therefore, when you are through using it, call [WinBioFree](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiofree) to release the allocated memory and avoid leaks. Because this also releases all nested data structures, you should not keep a copy of any pointers returned in the **WINBIO_ASYNC_RESULT** structure. If you want to save any data returned in a nested structure, make a private copy of that data before calling **WinBioFree**.

**Windows 8, Windows Server 2012, Windows 8.1 and Windows Server 2012 R2:** The Windows Biometric Framework supports only fingerprint readers. Therefore, if an operation fails and returns additional information in a **WINBIO_REJECT_DETAIL** constant, it will be one of the following values:

* WINBIO_FP_TOO_HIGH
* WINBIO_FP_TOO_LOW
* WINBIO_FP_TOO_LEFT
* WINBIO_FP_TOO_RIGHT
* WINBIO_FP_TOO_FAST
* WINBIO_FP_TOO_SLOW
* WINBIO_FP_POOR_QUALITY
* WINBIO_FP_TOO_SKEWED
* WINBIO_FP_TOO_SHORT
* WINBIO_FP_MERGE_FAILURE

Further, if an operation uses a **WINBIO_BIOMETRIC_SUBTYPE** data type, it will be one of the following values:

* WINBIO_ANSI_381_POS_UNKNOWN
* WINBIO_ANSI_381_POS_RH_THUMB
* WINBIO_ANSI_381_POS_RH_INDEX_FINGER
* WINBIO_ANSI_381_POS_RH_MIDDLE_FINGER
* WINBIO_ANSI_381_POS_RH_RING_FINGER
* WINBIO_ANSI_381_POS_RH_LITTLE_FINGER
* WINBIO_ANSI_381_POS_LH_THUMB
* WINBIO_ANSI_381_POS_LH_INDEX_FINGER
* WINBIO_ANSI_381_POS_LH_MIDDLE_FINGER
* WINBIO_ANSI_381_POS_LH_RING_FINGER
* WINBIO_ANSI_381_POS_LH_LITTLE_FINGER
* WINBIO_ANSI_381_POS_RH_FOUR_FINGERS
* WINBIO_ANSI_381_POS_LH_FOUR_FINGERS
* WINBIO_ANSI_381_POS_TWO_THUMBS

## See also

[WINBIO_REJECT_DETAIL Constants](https://learn.microsoft.com/windows/desktop/SecBioMet/winbio-reject-detail-constants)

[WinBioAsyncOpenFramework](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioasyncopenframework)

[WinBioAsyncOpenSession](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioasyncopensession)