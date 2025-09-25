# IAccClientDocMgr::GetDocuments

## Description

Clients call **IAccClientDocMgr::GetDocuments** to get a list of all documents that have been registered with the Microsoft Active Accessibility run time.

**Note** Active Accessibility Text Services is deprecated. Please see
[Microsoft Windows Text Services Framework](https://learn.microsoft.com/windows/win32/tsf/text-services-framework) for more information on advanced text input and natural language technologies.

## Parameters

### `enumUnknown` [out]

Type: **IEnumUnknown***

A list of document interface pointers.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If successful, returns S_OK.

## Remarks

Servers might need to poll this method more than once before they receive a document. There can be a limited time lapse (approximately second) between when a document appears in the system and when it is registered with document services.