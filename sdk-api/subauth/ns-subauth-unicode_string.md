# UNICODE_STRING structure

## Description

The **UNICODE_STRING** structure is used by various [Local Security Authority](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly) (LSA) functions to specify a [Unicode](https://learn.microsoft.com/windows/desktop/SecGloss/u-gly) string.

## Members

### `Length`

Specifies the length, in bytes, of the string pointed to by the **Buffer** member, not including the terminating **NULL** character, if any.

**Windows 7, Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** When the **Length** structure member is zero and the **MaximumLength** structure member is 1, the **Buffer** structure member can be an empty string or contain solely a null character. This behavior changed beginning with Windows Server 2008 R2 and Windows 7 with SP1.

### `MaximumLength`

Specifies the total size, in bytes, of memory allocated for **Buffer**. Up to **MaximumLength** bytes may be written into the buffer without trampling memory.

**Windows 7, Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** When the **Length** structure member is zero and the **MaximumLength** structure member is 1, the **Buffer** structure member can be an empty string or contain solely a null character. This behavior changed beginning with Windows Server 2008 R2 and Windows 7 with SP1.

### `Buffer`

Pointer to a wide-character string. Note that the strings returned by the various LSA functions might not be **null**-terminated.

**Windows 7, Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** When the **Length** structure member is zero and the **MaximumLength** structure member is 1, the **Buffer** structure member can be an empty string or contain solely a null character. This behavior changed beginning with Windows Server 2008 R2 and Windows 7 with SP1.