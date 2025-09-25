# ITfTransitoryExtensionSink::OnTransitoryExtensionUpdated

## Description

Transitory Document has been updated.

## Parameters

### `pic` [in]

[in] A pointer of [ITfContext](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfcontext) interface. This is a context object in which the update happened.

### `ecReadOnly` [in]

[in] A read only edit cookie to access the *pic*. Using this edit cookie, the application can get the text that is contained in the context object.

### `pResultRange` [in]

[in] A pointer of the [ITfRange](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfrange) interface. This is the range of the result string (determined string).

### `pCompositionRange` [in]

[in] A pointer of the [ITfRange](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfrange) interface. This is the range of the current composition string.

### `pfDeleteResultRange` [out]

[out] A pointer to return the bool value. If it is true, TSF manager deletes the result range so only the current composition range remains in the transitory extension.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | An unspecified error occurred. |