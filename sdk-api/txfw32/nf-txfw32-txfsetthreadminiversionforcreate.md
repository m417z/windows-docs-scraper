## Description

[Microsoft strongly recommends developers utilize alternative means to achieve your
application’s needs. Many scenarios that TxF was developed for can be achieved through simpler and more readily
available techniques. Furthermore, TxF may not be available in future versions of Microsoft Windows. For more
information, and alternatives to TxF, please see
[Alternatives to using Transactional NTFS](https://learn.microsoft.com/windows/desktop/FileIO/deprecation-of-txf).]

Sets the MiniVersion that a subsequent create should open. It should be returned to its previous state after calling create. Therefore, prior
to calling this routine, the caller should invoke [TxfGetThreadMiniVersionForCreate](https://learn.microsoft.com/windows/win32/api/txfw32/nf-txfw32-txfgetthreadminiversionforcreate).

## Parameters

### `MiniVersion`

A USHORT identifying which version should be opened by create.

## Remarks

## See also