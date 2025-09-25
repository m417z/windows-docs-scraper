# ITfInputProcessorProfiles::ActivateLanguageProfile

## Description

Sets the active text service for a specific language.

## Parameters

Sets the active text service for a specific language.

### `rclsid` [in]

Contains the CLSID of the text service to make active.

### `langid` [in]

Contains a **LANGID** value that specifies which language to set the default profile for. This method fails if this is not the currently active language.

### `guidProfiles` [in]

Contains a GUID value that identifies the language profile to make active.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | An unspecified error occurred. |
| **E_INVALIDARG** | One or more parameters are invalid. |
| **E_OUTOFMEMORY** | A memory allocation failure occurred. |
| **E_UNEXPECTED** | No thread manager has been created for the calling thread. |