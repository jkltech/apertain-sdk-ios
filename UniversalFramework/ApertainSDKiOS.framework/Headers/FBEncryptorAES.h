

//#import <CommonCrypto/CommonCryptor.h>
#import <Foundation/Foundation.h>
//#import <CommonCrypto/CommonHMAC.h>

#define FBENCRYPT_ALGORITHM     kCCAlgorithmAES128
#define FBENCRYPT_BLOCK_SIZE    kCCBlockSizeAES128
#define FBENCRYPT_KEY_SIZE      kCCKeySizeAES256

@interface FBEncryptorAES : NSObject {
    
}

//-----------------
// API (raw data)
//-----------------
+ (NSData*)generateIv;
+ (NSData*)encryptData:(NSData*)data key:(NSData*)key iv:(NSData*)iv;
+ (NSData*)decryptData:(NSData*)data key:(NSData*)key iv:(NSData*)iv;


//-----------------
// API (base64)
//-----------------
// the return value of encrypteMessage: and 'encryptedMessage' are encoded with base64.
//
+ (NSString*)encryptBase64String:(NSString*)string keyString:(NSString*)keyString separateLines:(BOOL)separateLines;
+ (NSString*)decryptBase64String:(NSString*)encryptedBase64String keyString:(NSString*)keyString;

//-----------------
// API (utilities)
//-----------------
+ (NSString*)hexStringForData:(NSData*)data;
+ (NSData*)dataForHexString:(NSString*)hexString;

//-----------------
//API SHA-Encryption
//-----------------
+(NSString*)sha256:(NSString*)data;
+(NSString*)sha512:(NSString*)data;


@end