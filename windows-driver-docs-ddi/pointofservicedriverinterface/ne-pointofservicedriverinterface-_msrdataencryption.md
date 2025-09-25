# _MsrDataEncryption enumeration

## Description

This enumeration defines the kind of encryption algorithm supported by the magnetic stripe reader (MSR).

## Constants

### `MsrDataEncryption_None`

Indicates no encryption algorithm.

### `MsrDataEncryption_3DEA_DUKPT`

The Triple Data Encryption Standard (DES) Derived Unique Key Per Transaction (DUKPT) encryption algorithm.

### `MsrDataEncryption_AES`

The Advanced Encryption Standard (AES).

### `MsrDataEncryption_ExtendedBase`

A vendor-specific encryption algorithm. Service-specific values begin at 0x01000000 and are reserved for additional encryption algorithms.