# IFEDictionary::GetHeader

## Description

Gets a dictionary header from a dictionary file without opening the dictionary.

## Parameters

### `pchDictPath` [in, out, optional]

A **NULL**-terminated string containing the path and name of the dictionary file.

### `pshf` [out]

The [IMESHF](https://learn.microsoft.com/windows/desktop/api/msime/ns-msime-imeshf) header of the file. Can be **NULL**.

### `pjfmt` [out]

The dictionary format. This can be one of the following values:

#### IFED_UNKNOWN

#### IFED_MSIME2_BIN_SYSTEM

#### IFED_MSIME2_BIN_USER

#### IFED_MSIME2_TEXT_USER

#### IFED_MSIME95_BIN_SYSTEM

#### IFED_MSIME95_BIN_USER

#### IFED_MSIME95_TEXT_USER

#### IFED_MSIME97_BIN_SYSTEM

#### IFED_MSIME97_BIN_USER

#### IFED_MSIME97_TEXT_USER

#### IFED_MSIME98_BIN_SYSTEM

#### IFED_MSIME98_BIN_USER

#### IFED_MSIME98_TEST_USER

#### IFED_ACTIVE_DICT

#### IFED_ATOK9

#### IFED_ATOK10

#### IFED_NEC_AI_

#### IFED_WX_II

#### IFED_WX_III

#### IFED_VJE_20

#### IFED_MSIME98_SYSTEM_CE

#### IFED_MSIME_BIN_SYSTEM

#### IFED_MSIME_BIN_USER

#### IFED_MSIME_TEXT_USER

#### IFED_PIME2_BIN_USER

#### IFED_PIME2_BIN_SYSTEM

#### IFED_PIME2_BIN_STANDARD_SYSTEM

### `pulType` [out]

The dictionary type. This is a combination of one or more of the following flags:

| Value | Meaning |
| --- | --- |
| **IFED_TYPE_NONE** | Undefined. |
| **IFED_TYPE_GENERAL** | General dictionary. |
| **IFED_TYPE_NAMEPLACE** | Name/place dictionary. |
| **IFED_TYPE_SPEECH** | Speech dictionary. |
| **IFED_TYPE_REVERSE** | Reverse dictionary. |
| **IFED_TYPE_ENGLISH** | English dictionary. |
| **IFED_TYPE_ALL** | All of the above types. |

## Return value

One of the following:

* **S_OK**
* **IFED_E_INVALID_FORMAT**
* **E_FAIL**

## See also

[IFEDictionary](https://learn.microsoft.com/windows/desktop/api/msime/nn-msime-ifedictionary)

[IMESHF](https://learn.microsoft.com/windows/desktop/api/msime/ns-msime-imeshf)