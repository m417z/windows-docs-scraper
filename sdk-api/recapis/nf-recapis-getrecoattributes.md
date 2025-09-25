# GetRecoAttributes function

## Description

Retrieves the attributes of the recognizer.

## Parameters

### `hrec`

Handle to the recognizer.

### `pRecoAttrs`

The attributes of the recognizer. The attributes define the languages and capabilities that the recognizer supports. For more information, see the [RECO_ATTRS](https://learn.microsoft.com/windows/desktop/api/rectypes/ns-rectypes-reco_attrs) structure.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | An invalid argument was received. |
| **E_POINTER** | The parameter is an invalid pointer. |
| **E_FAIL** | An unspecified error occurred. |

## Remarks

A gesture recognizer should set the RF_OBJECT bit of the [RECO_ATTRS](https://learn.microsoft.com/windows/desktop/api/rectypes/ns-rectypes-reco_attrs)**::dwRecoCapabilityFlags** and should set every element in the **RECO_ATTRS****::awLanguageID** array to zero.

A gesture recognizer does not normally use a recognition guide. A gesture recognizer with no guide should clear the RF_LINED_INPUT and RF_BOXED_INPUT bits.

The *awcFriendlyName* parameter of the [RECO_ATTRS](https://learn.microsoft.com/windows/desktop/api/rectypes/ns-rectypes-reco_attrs) structure may be empty (that is, having the first element set to the null character) when you use this structure as a return value from the **GetRecoAttributes Function**. Because this is not an error, the return code for *awcFriendlyName* in **GetRecoAttributes Function** will be S_OK, and the other fields will contain data.

## See also

[RECO_ATTRS Structure](https://learn.microsoft.com/windows/desktop/api/rectypes/ns-rectypes-reco_attrs)