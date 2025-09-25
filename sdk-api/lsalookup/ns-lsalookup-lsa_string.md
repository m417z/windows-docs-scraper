# LSA_STRING structure

## Description

The **LSA_STRING** structure is used by [Local Security Authority](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly) (LSA) functions to specify an ANSI string.

## Members

### `Length`

Specifies the length, in bytes, of the string in **Buffer**. This value does not include the terminating null character, if any.

When the **Length** structure member is zero and the **MaximumLength** structure member is 1, the **Buffer** structure member must not be an empty string or contain solely a null character.

**Windows 7, Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** When the **Length** structure member is zero and the **MaximumLength** structure member is 1, the **Buffer** structure member can be an empty string or contain solely a null character. This behavior changed beginning with Windows Server 2008 R2 and Windows 7 with SP1.

### `MaximumLength`

Specifies the total size, in bytes, of **Buffer**. Up to **MaximumLength** bytes may be written into the buffer without trampling memory.

When the **Length** structure member is zero and the **MaximumLength** structure member is 1, the **Buffer** structure member must not be an empty string or contain solely a null character.

**Windows 7, Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** When the **Length** structure member is zero and the **MaximumLength** structure member is 1, the **Buffer** structure member can be an empty string or contain solely a null character. This behavior changed beginning with Windows Server 2008 R2 and Windows 7 with SP1.

### `Buffer`

Pointer to an array of characters. Note that strings returned by the LSA may not be null-terminated.

When the **Length** structure member is zero and the **MaximumLength** structure member is 1, the **Buffer** structure member must not be an empty string or contain solely a null character.

**Windows 7, Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** When the **Length** structure member is zero and the **MaximumLength** structure member is 1, the **Buffer** structure member can be an empty string or contain solely a null character. This behavior changed beginning with Windows Server 2008 R2 and Windows 7 with SP1.