## Description

The `UnlockForProcess` method releases the lock that was imposed on the APO by the LockForProcess method.

## Return value

The `UnlockForProcess` method returns a value of S_OK if the call completed successfully. If the APO was already unlocked when the call was made, the method returns a value of APOERR_ALREADY_UNLOCKED.

## Remarks

The `UnlockForProcess` method places the APO in a mode that makes configuration changes possible. These changes include Add, Remove, and Swap of the input and output connections that are attached to the APO.