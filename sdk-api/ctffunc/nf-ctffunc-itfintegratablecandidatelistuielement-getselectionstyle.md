# ITfIntegratableCandidateListUIElement::GetSelectionStyle

## Description

Retrieves the selection style.

## Parameters

### `ptfSelectionStyle` [out]

A value that specifies the selection style.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

The active selection style usually indicates that the selection can be changed with the arrow keys. The implied selection style indicates the default selection key chooses it.
If the app supports changing selection styles, this method should be called when the [UpdateUIElement](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfuielementmgr-updateuielement) method is called.

## See also

[ITfIntegratableCandidateListUIElement](https://learn.microsoft.com/windows/desktop/api/ctffunc/nn-ctffunc-itfintegratablecandidatelistuielement)