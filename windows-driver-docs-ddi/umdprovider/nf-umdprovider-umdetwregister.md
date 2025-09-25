# UMDEtwRegister function

## Description

Registers the event trace provider. The driver should call this function before it makes any calls to log events.

## Parameters

### `CbRundown`

A pointer to a callback function that returns information about the current state of the user-mode driver.

This callback function should call the [UMDEtwLogMapAllocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/umdprovider/nf-umdprovider-umdetwlogmapallocation) function for every current allocation mapping.

## Remarks

The data type for the *CbRundown* parameter is defined as:

```cpp
typedef void (*PFNUMDETW_RUNDOWN)();
```

**UMDEtwRegister** is defined inline in Umdprovider.h as:

```cpp
// GUID for UMD ETW provider
// {A688EE40-D8D9-4736-B6F9-6B74935BA3B1}
static const GUID UMDEtwProviderId =
{ 0xa688ee40, 0xd8d9, 0x4736, { 0xb6, 0xf9, 0x6b, 0x74, 0x93, 0x5b, 0xa3, 0xb1 } };

// Registration handle, returned by EventRegister and passed to EventUnregister
__declspec(selectany) REGHANDLE RegHandle = NULL;

// Whether any level of logging is enabled.
__declspec(selectany) BOOLEAN Enabled = FALSE;

// Whether we are currently in a rundown
__declspec(selectany) BOOLEAN InRundown = FALSE;

// Callback to the driver when a rundown is needed
__declspec(selectany) PFNUMDETW_RUNDOWN Rundown = NULL;

FORCEINLINE void NTAPI EnableCallback(
  __in      LPCGUID SourceId,
  __in      ULONG IsEnabled,
  __in      UCHAR Level,
  __in      ULONGLONG MatchAnyKeyword,
  __in      ULONGLONG MatchAllKeywords,
  __in_opt  PEVENT_FILTER_DESCRIPTOR FilterData,
  __in_opt  PVOID CallbackContext
)
{
    switch (IsEnabled)
    {
        case EVENT_CONTROL_CODE_DISABLE_PROVIDER:
            Enabled = FALSE;
            break;
        case EVENT_CONTROL_CODE_ENABLE_PROVIDER:
            Enabled = TRUE;
            break;
        case EVENT_CONTROL_CODE_CAPTURE_STATE:
            // Temporarily enable logging during the rundown
            BOOLEAN OldEnabled = Enabled;
            Enabled = TRUE;

            InRundown = TRUE;
            Rundown();
            InRundown = FALSE;

            // Restore Enabled to its original state
            Enabled = OldEnabled;

            break;
    }
}

FORCEINLINE void UMDEtwRegister(PFNUMDETW_RUNDOWN RundownCb)
{
    Rundown = RundownCb;

    // Register the provider
    EventRegister(&UMDEtwProviderId,
                  EnableCallback,
                  NULL,
                  &RegHandle);
}
```

The [EventRegister](https://learn.microsoft.com/windows/win32/api/evntprov/nf-evntprov-eventregister) function and the **EVENT_CONTROL_CODE_XXX** values are described in the [Windows Events](https://learn.microsoft.com/windows/desktop/Events/windows-events) documentation.

## See also

[UMDEtwLogMapAllocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/umdprovider/nf-umdprovider-umdetwlogmapallocation)

[UMDEtwUnregister](https://learn.microsoft.com/windows-hardware/drivers/ddi/umdprovider/nf-umdprovider-umdetwunregister)