# ITfFnLMProcessor::InvokeFunc

## Description

Invokes a function of the language model text service.

## Parameters

### `pic` [in]

Pointer to an [ITfContext](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfcontext) interface that represents context to perform the function on.

### `refguidFunc` [in]

Contains a GUID that specifies the function to invoke. Possible values for this parameter are defined by the language model text service provider.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## See also

[ITfContext](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfcontext)

[ITfFnLMProcessor](https://learn.microsoft.com/windows/desktop/api/ctffunc/nn-ctffunc-itffnlmprocessor)