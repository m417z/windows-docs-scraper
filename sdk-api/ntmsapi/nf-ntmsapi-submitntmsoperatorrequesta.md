# SubmitNtmsOperatorRequestA function

## Description

[[Removable Storage Manager](https://learn.microsoft.com/previous-versions/windows/desktop/bb540725(v=vs.85)) is no longer available as of Windows 7 and Windows Server 2008 R2.]

The
**SubmitNtmsOperatorRequest** function submits an RSM operator request.

## Parameters

### `hSession` [in]

Handle to the session returned by the
[OpenNtmsSession](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-openntmssessiona) function.

### `dwRequest` [in]

Type of operator request. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **NTMS_OPREQ_CLEANER** | RSM sends an operator request to insert a cleaner when a clean operation is queued and no cleaner is available to the drive. The *lpArg1Id* parameter can be either a library or slot identifier.<br><br> Requires NTMS_CONTROL_ACCESS to the library.<br><br>**Windows XP:** No access rights are required. |
| **NTMS_OPREQ_DEVICESERVICE** | An application or RSM sends an operator request for drive service when a changer device or drive is experiencing problems. The *lpArg1Id* parameter specifies the device that needs service. This parameter can be an iedoor, library, physical media, or drive identifier.<br><br> Requires NTMS_CONTROL_ACCESS to the library.<br><br>**Windows XP:** No access rights are required. |
| **NTMS_OPREQ_MESSAGE** | Application message only.<br><br> Requires NTMS_USE_ACCESS to the computer.<br><br>**Windows XP:** No access rights are required. |
| **NTMS_OPREQ_MOVEMEDIA** | An application or RSM sends an operator request to move media from one library to another for a mount of offline media or to eject existing media to the offline library. The *lpArg1Id* parameter specifies the piece of physical media that must be moved and the *lpArg2Id* parameter specifies the target library.<br><br> Requires NTMS_CONTROL_ACCESS to the media pool.<br><br>**Windows XP:** No access rights are required. |
| **NTMS_OPREQ_NEWMEDIA** | An application or RSM sends an operator request for new media when no media is available. The *lpArg1Id* parameter specifies the media pool object and the *lpArg2Id* parameter is the optional library identifier to which to add the new medium.<br><br> Requires NTMS_CONTROL_ACCESS to the media pool.<br><br>**Windows XP:** No access rights are required. |

### `lpMessage` [in]

Optional message string to be sent to the user.

### `lpArg1Id` [in]

Object identifier for the operator request. Refer to the descriptions of the values in the *dwRequest* parameter for a description of what type of object must be passed for this parameter.

### `lpArg2Id` [in]

Object identifier for the operator request. Refer to the descriptions of the values in the *dwRequest* parameter for details on what type of object must be passed for this parameter.

### `lpRequestId` [out]

Pointer to a buffer that receives the identifier of the operator request that was created.

## Return value

This function returns one of the following values.

| Value | Meaning |
| --- | --- |
| **ERROR_ACCESS_DENIED** | Access to one or more RSM objects is denied. |
| **ERROR_DATABASE_FAILURE** | The database query or update failed. |
| **ERROR_INVALID_HANDLE** | The value specified in the *hSession* parameter is **NULL** or is not valid. |
| **ERROR_INVALID_PARAMETER** | One of the parameter values is not valid. |
| **ERROR_NOT_CONNECTED** | Unable to connect to the RSM service. |
| **ERROR_OBJECT_NOT_FOUND** | Unable to find the source or destination object. |
| **ERROR_SUCCESS** | The function was successful. |

## Remarks

The
**SubmitNtmsOperatorRequest** function submits an operator request and returns the status of the request (Satisfied or Canceled) or times out (if the operator does not act upon the request). Operator requests are used to request media, to request that the specified medium be moved from one library to another, or to request RSM device service.

The NTMS_OPEREQ_MESSAGE value (in the *dwRequest* parameter) is the request type most often used by applications. RSM cannot use NTMS_OPEREQ_MESSAGE. RSM uses the other request types as needed.

> [!NOTE]
> The ntmsapi.h header defines SubmitNtmsOperatorRequest as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[AllocateNtmsMedia](https://learn.microsoft.com/previous-versions/windows/desktop/rsm/media)

[CancelNtmsOperatorRequest](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-cancelntmsoperatorrequest)

[MountNtmsMedia](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-mountntmsmedia)

[Operator Request Functions](https://learn.microsoft.com/previous-versions/windows/desktop/rsm/removable-storage-manager-functions)

[SatisfyNtmsOperatorRequest](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-satisfyntmsoperatorrequest)

[WaitForNtmsOperatorRequest](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-waitforntmsoperatorrequest)