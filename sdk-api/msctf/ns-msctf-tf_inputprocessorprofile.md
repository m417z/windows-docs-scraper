# TF_INPUTPROCESSORPROFILE structure

## Description

This structure contains data for the input processor profile.

## Members

### `dwProfileType`

The type of this profile. This is one of these values.

| Value | Meaning |
| --- | --- |
| TF_PROFILETYPE_INPUTPROCESSOR | This is a text service. |
| TF_PROFILETYPE_KEYBOARDLAYOUT | This is a keyboard layout. |

### `langid`

The language id for this profile.

### `clsid`

The CLSID of the text service. This is CLSID_NULL if this profile is a keyboard layout.

### `guidProfile`

The guidProfile of the text services. This is GUID_NULL if this profile is a keyboard layout.

### `catid`

The category of this text service. This category is GUID_TFCAT_TIP_KEYBOARD, GUID_TFCAT_TIP_SPEECH, GUID_TFCAT_TIP_HANDWRITING or something in GUID_TFCAT_CATEGORY_OF_TIP.

### `hklSubstitute`

The keyboard layout handle of the substitute for this text service. This can be **NULL** if the text service does not have a substitute or this profile is a keyboard layout.

### `dwCaps`

The flag to specify the capability of text service. This is the combination of the following flags:

| Value | Meaning |
| --- | --- |
| TF_IPP_CAPS_DISABLEONTRANSITORY | This text service profile is disabled on transitory context. |
| TF_IPP_CAPS_SECUREMODESUPPORT | This text service supports the secure mode. This is categorized in GUID_TFCAT_TIPCAP_SECUREMODE. |
| TF_IPP_CAPS_UIELEMENTENABLED | This text service supports the UIElement. This is categorized in GUID_TFCAT_TIPCAP_UIELEMENTENABLED. |
| TF_IPP_CAPS_COMLESSSUPPORT | This text service can be activated without COM. This is categorized in GUID_TFCAT_TIPCAP_COMLESS. |
| TF_IPP_CAPS_WOW16SUPPORT | This text service can be activated on 16bit task. This is categorized in GUID_TFCAT_TIPCAP_WOW16. |
| TF_IPP_CAPS_IMMERSIVESUPPORT | **Starting with Windows 8:** This text service has been tested to run properly in a Windows Store app. |
| TF_IPP_CAPS_SYSTRAYSUPPORT | **Starting with Windows 8:** This text service supports inclusion in the System Tray. This is used for text services that do not set the TF_IPP_CAPS_IMMERSIVESUPPORT flag but are still compatible with the System Tray. |

### `hkl`

The keyboard layout handle. This is **NULL** if this profile is a text service.

### `dwFlags`

The flag for this profile. This is a combination of the following flags:

| Value | Meaning |
| --- | --- |
| TF_IPP_FLAG_ACTIVE | This profile is now active. |
| TF_IPP_FLAG_ENABLED | This profile is enabled. |
| TF_IPP_FLAG_SUBSTITUTEDBYINPUTPROCESSOR | This profile is substituted by a text service. |