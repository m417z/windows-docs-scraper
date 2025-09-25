# ITextStoreACP2::AdviseSink

## Description

Installs a new advise sink from the [ITextStoreACPSink](https://learn.microsoft.com/windows/desktop/api/textstor/nn-textstor-itextstoreacpsink) interface or modifies an existing advise sink. The sink interface is specified by the *punk* parameter.

## Parameters

### `riid` [in]

Specifies the sink interface.

### `punk` [in]

Pointer to the sink interface. Cannot be **NULL**.

### `dwMask` [in]

Specifies the events that notify the advise sink. For more information about possible parameter values, see [TS_AS_* Constants](https://learn.microsoft.com/windows/desktop/TSF/ts-as--constants).

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **CONNECT_E_ADVISELIMIT** | A sink interface pointer could not be obtained. |
| **E_INVALIDARG** | The specified sink interface is unsupported. |
| **E_UNEXPECTED** | The specified sink object could not be obtained. |

## See also

[ITextStoreACP2](https://learn.microsoft.com/windows/desktop/api/textstor/nn-textstor-itextstoreacp2)