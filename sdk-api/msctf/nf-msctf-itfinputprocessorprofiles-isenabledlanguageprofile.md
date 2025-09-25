# ITfInputProcessorProfiles::IsEnabledLanguageProfile

## Description

Determines if a specific language profile is enabled or disabled.

## Parameters

### `rclsid` [in]

Contains the CLSID of the text service of the profile in question.

### `langid` [in]

Contains a **LANGID** value that specifies the language of the profile in question.

### `guidProfile` [in]

Contains a GUID value that identifies the profile in question.

### `pfEnable` [out]

Pointer to a **BOOL** value that receives a value that specifies if the profile is enabled or disabled. If this receives a nonzero value, the profile is enabled. If this receives zero, the profile is disabled.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_INVALIDARG** | *pfEnable* is invalid. |