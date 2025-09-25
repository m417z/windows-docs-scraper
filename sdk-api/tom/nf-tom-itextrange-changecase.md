# ITextRange::ChangeCase

## Description

Changes the case of letters in this range according to the
*Type* parameter.

## Parameters

### `Type` [in]

Type: **long**

Type of case change. The default value is *tomLower*.

| Value | Meaning |
| --- | --- |
| **tomLowerCase**<br><br>0 | Sets all text to lowercase. |
| **tomUpperCase**<br><br>1 | Sets all text to lowercase. |
| **tomTitleCase**<br><br>2 | Capitalizes the first letter of each word. |
| **tomSentenceCase**<br><br>4 | Capitalizes the first letter of each sentence. |
| **tomToggleCase**<br><br>5 | Toggles the case of each letter. |

## Return value

Type: **HRESULT**

This method returns an
**HRESULT** value. If successful, it returns **S_OK**. Otherwise, it returns S_FALSE.

## See also

**Conceptual**

[ITextRange](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange)

**Reference**

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)