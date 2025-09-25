# ITfLanguageProfileNotifySink::OnLanguageChange

## Description

Called when the language profile is about to change.

## Parameters

### `langid` [in]

Contains a **LANGID** value the identifies the new language profile.

### `pfAccept` [out]

Pointer to a **BOOL** value that receives a flag that permits or prevents the language profile change. Receives zero to prevent the language profile change or nonzero to permit the language profile change.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |