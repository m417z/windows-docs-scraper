# ITfInputProcessorProfiles::SetDefaultLanguageProfile

## Description

Sets the default profile for a specific language.

## Parameters

### `langid` [in]

Contains a LANGID value that specifies which language to set the default profile for.

### `rclsid` [in]

Contains the CLSID of the text service that will be the default for the language.

### `guidProfiles` [in]

Contains a GUID value that identifies the language profile that will be the default.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | An unspecified error occurred. |
| **E_INVALIDARG** | One or more parameters are invalid. |