## Description

The **SecAllocateAndSetIPAddress** function allocates resources and sets a call target based on an IP address and optional target name.

## Parameters

### `lpIpAddress`

[in, optional] A pointer to a buffer containing the IP address of the target. This parameter can be NULL if only the target name is provided.

### `cchIpAddress`

[in] The size, in bytes, of the IP address buffer.

### `TargetName`

[in, optional] A pointer to a wide string representing the canonical name of the target. This can be used to determine the nature of the resource.

### `FreeCallContext`

[out] Pointer to an integer that indicates whether the call context should be freed. This value is equivalent to a Boolean value, where a non-zero value (TRUE) indicates that the caller is responsible for freeing the context by calling [**SecFreeCallContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-secfreecallcontext).

## Return value

**SecAllocateAndSetIPAddress** returns SEC_E_OK if the operation is successful. Otherwise, it returns an error code such as one of the following:

| Return code | Description |
| ----------- | ----------- |
| SEC_E_INVALID_PARAMETER | One or more parameters are invalid. |
| SEC_E_INSUFFICIENT_MEMORY | There is not enough memory to complete the operation. |

## Remarks

**SecAllocateAndSetIPAddress** is primarily used to determine if a target is a private or enterprise resource, facilitating Single Sign-On (SSO) operations.

It allows both an IP address and a target name to be specified, providing flexibility in identifying the target resource. One of **lpIpAddress** or **TargetName** must be provided; otherwise, the function will return SEC_E_INVALID_PARAMETER.

## See also

[**SecAllocateAndSetCallTarget**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-secallocateandsetcalltarget)

[**SecFreeCallContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-secfreecallcontext)