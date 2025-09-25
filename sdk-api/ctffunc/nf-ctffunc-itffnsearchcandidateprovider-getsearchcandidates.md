# ITfFnSearchCandidateProvider::GetSearchCandidates

## Description

Gets a list of conversion candidates for a given string without generating any IME-related messages or events.

## Parameters

### `bstrQuery` [in]

A string that specifies the reading string that the text service attempts to convert.

### `bstrApplicationId` [in]

App-specified string that enables a text service to optionally provide different candidates to different apps or contexts based on input history. You can pass an empty **BSTR**, L””, for a generic context.

### `pplist` [out]

An [ITfCandidateList](https://learn.microsoft.com/windows/desktop/api/ctffunc/nn-ctffunc-itfcandidatelist) that receives the requested candidate data.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **S_FALSE** | No candidates could be returned for the input string, *pplist* may be **NULL**. |

## See also

[ITfFnSearchCandidateProvider](https://learn.microsoft.com/windows/desktop/api/ctffunc/nn-ctffunc-itffnsearchcandidateprovider)

[SearchPaneQueryLinguisticDetails](https://learn.microsoft.com/uwp/api/windows.applicationmodel.search.searchpanequerylinguisticdetails)

[SetResult](https://learn.microsoft.com/windows/desktop/api/ctffunc/nf-ctffunc-itfcandidatelist-setresult)