# ITfFnSearchCandidateProvider::SetResult

## Description

Provides a text Service or IME with history data when a candidate is chosen by the user.

## Parameters

### `bstrQuery` [in]

The reading string for the text service or IME to convert.

### `bstrApplicationID` [in]

App-specified string that enables a text service or IME to optionally provide different candidates to different apps or contexts based on input history. You can pass an empty **BSTR**, L””, for a generic context.

### `bstrResult` [in]

A string that represents the candidate string chosen by the user. It should be one of the candidate string values returned by the [GetSearchCandidates](https://learn.microsoft.com/windows/desktop/api/ctffunc/nf-ctffunc-itffnsearchcandidateprovider-getsearchcandidates) method.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

Implementing and calling the [SetResult](https://learn.microsoft.com/windows/desktop/api/ctffunc/nf-ctffunc-itfcandidatelist-setresult) method is optional.

A text service or IME can return **E_PENDING** if no corresponding call to [GetSearchCandidates](https://learn.microsoft.com/windows/desktop/api/ctffunc/nf-ctffunc-itffnsearchcandidateprovider-getsearchcandidates) has been made yet for the value of *bstrQuery*.

## See also

[GetSearchCandidates](https://learn.microsoft.com/windows/desktop/api/ctffunc/nf-ctffunc-itffnsearchcandidateprovider-getsearchcandidates)

[ITfFnSearchCandidateProvider](https://learn.microsoft.com/windows/desktop/api/ctffunc/nn-ctffunc-itffnsearchcandidateprovider)