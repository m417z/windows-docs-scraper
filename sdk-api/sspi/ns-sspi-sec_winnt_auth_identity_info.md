## Description

Contains the identity information for authentication.

## Members

### `AuthIdExw`

The **AuthIdExw** authentication identity.

### `AuthIdExa`

The **AuthIdExa** authentication identity.

### `AuthId_a`

The **AuthId_a** authentication identity.

### `AuthId_w`

The **AuthId_w** authentication identity.

### `AuthIdEx2`

The **AuthIdEx2** authentication identity.

## Remarks

How to parse a **SEC_WINNT_AUTH_IDENTITY_INFO** structure:

1. First, check the first **DWORD** of **SEC_WINNT_AUTH_IDENTITY_INFO**. If the first **DWORD** is **0x200**, it is either an **AuthIdExw** or **AuthIdExA**. Otherwise, if the first **DWORD** is **0x201**, the structure is an **AuthIdEx2** structure. Otherwise, the structure is either an **AuthId_a** or an **AuthId_w**.

1. Secondly, check the flags for **SEC_WINNT_AUTH_IDENTITY_ANSI** or **SEC_WINNT_AUTH_IDENTITY_UNICODE**. The presence of the former means the structure is an ANSI structure. Otherwise, the structure is the wide version. Note that **AuthIdEx2** does not have an ANSI version, so this check does not apply to it.

## See also