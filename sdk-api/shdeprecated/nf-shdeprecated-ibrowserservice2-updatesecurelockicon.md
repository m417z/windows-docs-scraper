# IBrowserService2::UpdateSecureLockIcon

## Description

Deprecated. Updates the value of the **_eSecureLockIcon** member of the [BASEBROWSERDATA](https://learn.microsoft.com/windows/desktop/api/shdeprecated/ns-shdeprecated-basebrowserdatalh) structure, which tracks the icon indicating a secure site, as well as updating the icon itself in the UI.

## Parameters

### `eSecureLock` [in]

Type: **int**

One of the following values indicating the secure lock status. Note that each value is provided in a SET and SUGGEST form. For more details, see [BASEBROWSERDATA](https://learn.microsoft.com/windows/desktop/api/shdeprecated/ns-shdeprecated-basebrowserdatalh).

#### SECURELOCK_NOCHANGE

#### SECURELOCK_SET_UNSECURE

#### SECURELOCK_SET_MIXED

#### SECURELOCK_SET_SECUREUNKNOWNBIT

#### SECURELOCK_SET_SECURE40BIT

#### SECURELOCK_SET_SECURE56BIT

#### SECURELOCK_SET_FORTEZZA

#### SECURELOCK_SET_SECURE128BIT

#### SECURELOCK_FIRSTSUGGEST

#### SECURELOCK_SUGGEST_UNSECURE

#### SECURELOCK_SUGGEST_MIXED

#### SECURELOCK_SUGGEST_SECUREUNKNOWNBIT

#### SECURELOCK_SUGGEST_SECURE40BIT

#### SECURELOCK_SUGGEST_SECURE56BIT

#### SECURELOCK_SUGGEST_FORTEZZA

#### SECURELOCK_SUGGEST_SECURE128BIT

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

SECURELOCK_SUGGEST_UNSECURE is equivalent to SECURELOCK_FIRSTSUGGEST.