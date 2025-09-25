# _PROCESS_MITIGATION_PAYLOAD_RESTRICTION_POLICY structure

## Description

Stores information about process mitigation policy.

## Members

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.Flags`

Bitwise of flags in this structure.

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME`

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.EnableExportAddressFilter`

If set this enables the Export Address Filter mitigation in enforcement mode for the process.

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.AuditExportAddressFilter`

If set this enables the Export Address Filter mitigation in audit mode for the process.

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.EnableExportAddressFilterPlus`

If set this enables the Export Address Filter Plus mitigation in enforcement mode for the process.

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.AuditExportAddressFilterPlus`

If set this enables the Export Address Filter mitigation in audit mode for the process.

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.EnableImportAddressFilter`

If set this enables the Import Address Filter mitigation in enforcement mode for the process.

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.AuditImportAddressFilter`

If set this enables the Import Address Filter mitigation in enforcement mode for the process.

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.EnableRopStackPivot`

If set this enables the stack pivot anti-ROP (Return-oriented-programming) mitigation in enforcement mode for the process.

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.AuditRopStackPivot`

If set this enables the stack pivot anti-ROP (Return-oriented-programming) mitigation in audit mode for the process.

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.EnableRopCallerCheck`

If set this enables the caller check anti-ROP (Return-oriented-programming) mitigation in enforcement mode for the process. Applies to 32-bit processes only.

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.AuditRopCallerCheck`

If set this enables the caller check anti-ROP (Return-oriented-programming) mitigation in audit mode for the process. Applies to 32-bit processes only.

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.EnableRopSimExec`

If set this enables the simulated execution anti-ROP (Return-oriented-programming) mitigation in enforcement mode for the process. Applies to 32-bit processes only.

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.AuditRopSimExec`

If set this enables the simulated execution anti-ROP (Return-oriented-programming) mitigation in audit mode for the process. Applies to 32-bit processes only.

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.ReservedFlags`

Reserved.