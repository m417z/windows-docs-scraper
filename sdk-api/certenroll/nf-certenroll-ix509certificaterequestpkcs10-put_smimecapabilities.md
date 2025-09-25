# IX509CertificateRequestPkcs10::put_SmimeCapabilities

## Description

The **SmimeCapabilities** property specifies or retrieves a Boolean value that tells the [Encode](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequest-encode) method whether to create an [IX509ExtensionSmimeCapabilities](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509extensionsmimecapabilities) collection that identifies the encryption capabilities supported by the computer. This property is web enabled for both input and output.

This property is read/write.

## Parameters

## Remarks

Multipurpose Internet Mail Extensions (MIME) is a specification for formatting binary data into text so that it can be sent in email. Secure/Multipurpose Internet Mail Extensions (S/MIME) is a standard for encrypting and signing a MIME message.

The **SmimeCapabilities** extension, represented by an [IX509ExtensionSmimeCapabilities](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509extensionsmimecapabilities) object, is used when sending and receiving encrypted email messages to report the recipient's decryption capabilities to the sender. This enables the sender to choose the most secure algorithm supported by both the sender and recipient.

If you did not set the [SuppressDefaults](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequest-get_suppressdefaults) property before calling the [Encode](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequest-encode) method, the **SmimeCapabilities** extension is added by default and the available symmetric algorithm OIDs are enumerated and added to the extension value. Set the **SmimeCapabilities** property before calling **Encode**.

## See also

[IX509CertificateRequestPkcs10](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequestpkcs10)