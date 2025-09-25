# SECPKG_TARGETINFO structure

## Description

Specifies the target of an authentication request.

## Members

### `DomainSid`

A pointer to a [SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid) structure that specifies the domain of the target computer.

### `ComputerName`

The name of the target computer.

## See also

[SpValidateTargetInfoFn](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spvalidatetargetinfofn)