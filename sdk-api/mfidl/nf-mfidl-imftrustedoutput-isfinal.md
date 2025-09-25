# IMFTrustedOutput::IsFinal

## Description

Queries whether this output is a policy sink, meaning it handles the rights and restrictions required by the input trust authority (ITA).

## Parameters

### `pfIsFinal` [out]

Receives a Boolean value. If **TRUE**, this object is a policy sink. If **FALSE**, the policy must be enforced further downstream.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

A trusted output is generally considered to be a policy sink if it does not pass the media content that it receives anywhere else; or, if it does pass the media content elsewhere, either it protects the content using some proprietary method such as encryption, or it sufficiently devalues the content so as not to require protection.

## See also

[IMFTrustedOutput](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imftrustedoutput)