# ExpertGetFrame function

The **ExpertGetFrame** function returns the requested frame from a loaded capture.

## Parameters

*hExpertKey* \[in\]

A unique expert identifier. Network Monitor passes the *hExpertKey* identifier to the expert when it calls the [**Run**](https://learn.microsoft.com/windows/win32/netmon2/run) function.

*Direction* \[in\]

A value that identifies how Network Monitor searches for the frame.

| Value | Meaning |
|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|----------------------------------------|
|

**GET\_SPECIFIED\_FRAME**

| Return the requested frame.<br> |
|

**GET\_FRAME\_NEXT\_FORWARD**

| Return the next frame.<br> |
|

**GET\_FRAME\_NEXT\_BACKWARD**

| Return the previous frame.<br> |

*RequestFlags* \[in\]

The flags that specify how Network Monitor should handle the request. Specify one or more of the following flags.

| Value | Meaning |
|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
|

**FLAGS\_DEFER\_TO\_UI\_FILTER**

| Before applying the display filter parameter of the expert which is specified in *hFilter*, apply the display filter that Network Monitor is using when the expert starts.<br> |
|

**FLAGS\_ATTACH\_PROPERTIES**

| The properties that all protocol parsers find with claimed sections of this frame are attached to the frame. If the flag is not set, the **lpPropertyTable** field of the [**EXPERTFRAMEDESCRIPTOR**](https://learn.microsoft.com/windows/win32/netmon2/expertframedescriptor) structure (returned by **pEFrameDescriptor**) will be set to **NULL**.<br> |

*RequestedFrameNumber* \[in\]

The number of the requested frame.

*hFilter* \[in\]

A handle to the expert display filter. If the expert does not have a display filter, set the parameter to **NULL**.

*pEFrameDescriptor* \[out\]

The [**EXPERTFRAMEDESCRIPTOR**](https://learn.microsoft.com/windows/win32/netmon2/expertframedescriptor) structure that, on return, describes the frame. The expert must allocate and free the memory that this structure uses.

## Return value

If the function is successful, the return value is NMERR\_SUCCESS.

If the function is unsuccessful, the return value indicates the reason for the failure. If the return value is NMERR\_EXPERT\_TERMINATE, the expert must immediately clean up and return; the user has aborted the expert run.

## Remarks

If you set FLAGS\_ATTACH\_PROPERTIES, the call requires more resources than if you do not set the flag. If the flag is not set, a pointer points to the raw frame and to data about the frame. If this flag is set, Network Monitor attaches all properties to the frame by calling every parser that claims a portion of the frame. This can be a slow process.

Experts should not set the FLAGS\_ATTACH\_PROPERTIES flag unless the experts require the properties that parsers attach to the frame. If possible, experts should call the **ExpertGetFrame** function without the flag, and then extract the required data directly from the frame.

If the expert calls **ExpertGetFrame** without the FLAGS\_ATTACH\_PROPERTIES flag and requires the properties associated with that frame (an event, for example), the expert calls **ExpertGetFrame** with the same parameters except for the following:

``` syntax
Direction = EXPERT_GET_SPECIFIED_FRAME;
RequestFlags &= (~EXPERT_DEFER_TO_UI_FILTER) | EXPERT_ATTACH_PROPERTIES;
RequestedFrameNumber= (The actual frame number you want);
hFilter = NULL;
pEFrameDescriptor = (The same one as last time);
```

Using the preceding code ensures that the expert gets the required frame without having to call filter code again.

You can set the *hFilter* parameter as an **LPVOID**. If it exists, the returned frame passes this filter. If the expert does not have a display filter to pass to the function (if *hFilter* is **NULL** ), then the frame returned is not filtered.

The **ExpertGetFrame** function can only be called by experts that implement the [**Run**](https://learn.microsoft.com/windows/win32/netmon2/run) or [**Configure**](https://learn.microsoft.com/windows/win32/netmon2/configure) export function.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |
| Library<br> | Nmapi.lib |
| DLL<br> | Nmapi.dll |

