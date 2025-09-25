# ITfInputProcessorProfileActivationSink::OnActivated

## Description

The ITfInputProcessorProfileActivationSink::OnActivated method is a callback that is called when an input processor profile is activated or deactivated.

## Parameters

### `dwProfileType` [in]

[in] The type of this profile. This is one of these values.

| Value | Meaning |
| --- | --- |
| **TF_PROFILETYPE_INPUTPROCESSOR** | This is a text service. |
| **TF_PROFILETYPE_KEYBOARDLAYOUT** | This is a keyboard layout. |

### `langid` [in]

[in] Specifies the language id of the profile.

### `clsid` [in]

[in] Specifies the CLSID of the text service. If *dwProfileType* is TF_PROFILETYPE_KEYBOARDLAYOUT, this is CLSID_NULL.

### `catid` [in]

[in] Specifies the category of this text service. This category is GUID_TFCAT_TIP_KEYBOARD, GUID_TFCAT_TIP_SPEECH, GUID_TFCAT_TIP_HANDWRITING or something in GUID_TFCAT_CATEGORY_OF_TIP. If *dwProfileType* is TF_PROFILETYPE_KEYBOARDLAYOUT, this is GUID_NULL.

### `guidProfile` [in]

[in] Specifies the GUID to identify the profile. If *dwProfileType* is TF_PROFILETYPE_KEYBOARDLAYOUT, this is GUID_NULL.

### `hkl` [in]

[in] Specifies the keyboard layout handle of this profile. If *dwProfileType* is TF_PROFILETYPE_INPUTPROCESSOR, this is **NULL**.

### `dwFlags` [in]

[in]

| Value | Meaning |
| --- | --- |
| **TF_IPSINK_FLAG_ACTIVE** | This is on if this profile is activated. |

## Return value

The TSF manager ignores the return value of this method.