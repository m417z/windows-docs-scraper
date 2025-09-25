# ITfLangBarItemSink::OnUpdate

## Description

Notifies the language bar of a change in a language bar item.

## Parameters

### `dwFlags` [in]

Contains a set of flags that indicate changes in the language bar item. This can be a combination of one or more of the [TF_LBI_*](https://learn.microsoft.com/windows/desktop/TSF/tf-lbi--constants) values.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | An unspecified error occurred. |

## Remarks

A language bar item should call this method when the internal state of the item changes. TSF will update the language bar user interface appropriately.

## See also

[ITfLangBarItemSink](https://learn.microsoft.com/windows/desktop/api/ctfutb/nn-ctfutb-itflangbaritemsink)

[TF_LBI_* Constants](https://learn.microsoft.com/windows/desktop/TSF/tf-lbi--constants)