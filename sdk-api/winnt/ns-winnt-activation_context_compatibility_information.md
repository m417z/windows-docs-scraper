# ACTIVATION_CONTEXT_COMPATIBILITY_INFORMATION structure

## Description

The **ACTIVATION_CONTEXT_COMPATIBILITY_INFORMATION** structure is used by the [QueryActCtxW](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-queryactctxw) function.

## Members

### `ElementCount`

The number of compatibility elements defined in the application manifest.

### `Elements`

This is an array of [COMPATIBILITY_CONTEXT_ELEMENT](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-compatibility_context_element) structures. Each structure describes one compatibility element in the application manifest.

## Remarks

The following example requires Windows Server 2008 R2 or Windows 7 and shows the method to retrieve information about the compatibility context.

``` syntax
HANDLE   ActCtxHandle=INVALID_HANDLE_VALUE;
SIZE_T   BytesWritten=0;
PACTIVATION_CONTEXT_COMPATIBILITY_INFORMATION CtxCompatInfo=NULL;

// Query the compatibility information size
bReturn = QueryActCtxW(0,
                       ActCtxHandle,
                       NULL,
                       CompatibilityInformationInActivationContext,
                       NULL,
                       0,
                       &BytesWritten);

if (bReturn == FALSE && GetLastError() !=ERROR_INSUFFICIENT_BUFFER)
       {
	 goto EXIT;
	 }
	
CtxCompatInfo =
(PACTIVATION_CONTEXT_COMPATIBILITY_INFORMATION)HeapAlloc(GetProcessHeap(),
    HEAP_ZERO_MEMORY, BytesWritten);

if (CtxCompatInfo==NULL)
       {
	 // Out of memory
	 goto EXIT;
	 }

// Query the compatibility information
bReturn = QueryActCtxW(0,
                       ActCtxHandle,
                       NULL,
                       CompatibilityInformationInActivationContext,
                       CtxCompatInfo,
                       BytesWritten,
                       &BytesWritten);

if (bReturn==FALSE)
       {
        // Unexpected error: use GetLastError() to check
        goto EXIT;
	 }

for (DWORD ElementIndex=0; ElementIndex < CtxCompatInfo->ElementCount; ElementIndex ++)
{
PCOMPATIBILITY_CONTEXT_ELEMENT ContextElement = &CtxCompatInfo->Elements[ElementIndex];
if (ContextElement->Type == ACTCTX_COMPATIBILITY_ELEMENT_TYPE_OS)
       {
       if (memcmp(&ContextElement->Id, &WIN7_CONTEXT_GUID, sizeof (GUID))==0)
             {printf_s("Windows 7 is supported");}
	 }
}
	
EXIT:
if (ActCtxHandle != INVALID_HANDLE_VALUE)
       {
        ReleaseActCtx (ActCtxHandle)
	 }
if (CtxCompatInfo != NULL)
       {
        RtlFreeHeap (RtlProcessHeap (), 0, CtxCompatInfo);
        CtxCompatInfo = NULL;
	 }

```