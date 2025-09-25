# CERT_PAIR structure

## Description

The **CERT_PAIR** structure contains a certificate and its pair cross certificate.

## Members

### `Forward`

An optional [CERT_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure that contains a certificate. If the **cbData** member of **Forward** is zero, the certificate may be empty.

### `Reverse`

An optional [CERT_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure that contains a certificate. If the **cbData** member of **Reverse** is zero, the certificate may be empty.