//  XMPPPubSub.h
//  Created by Duncan Robertson [duncan@whomwah.com]
//  Updated by Nadim for Novedia Group - Hubiquitus project[hubiquitus.com]

#import <Foundation/Foundation.h>
#import "XMPPModule.h"

#if TARGET_OS_IPHONE
#import "DDXML.h"
#endif

@class XMPPStream;
@class XMPPJID;
@class XMPPIQ;
@class XMPPMessage;

@interface XMPPPubSub : XMPPModule {
	XMPPJID *serviceJID;
}

- (id)initWithServiceJID:(XMPPJID *)aServiceJID;
- (id)initWithServiceJID:(XMPPJID *)aServiceJID dispatchQueue:(dispatch_queue_t)queue;

@property (nonatomic, readonly) XMPPJID *serviceJID;

- (NSString *)subscribeToNode:(NSString *)node withOptions:(NSDictionary *)options;
- (NSString *)unsubscribeFromNode:(NSString *)node withSubid:(NSString *)subid;
- (NSString *)unsubscribeFromNode:(NSString *)node;
- (NSString *)createNode:(NSString *)node withOptions:(NSDictionary *)options;
- (NSString *)deleteNode:(NSString *)node;
- (NSString *)configureNode:(NSString *)node;
- (NSString *)allItemsForNode:(NSString *)node;
- (NSString *)publishToNode:(NSString*)node entry:(NSXMLElement*)entry;
- (NSString *)discoverItemsForNode:(NSString*)node;
- (NSString *)getSubscriptions;
- (NSString *)getSubscriptionsForNode:(NSString*)node;

@end

@protocol XMPPPubSubDelegate
@optional

- (void)xmppPubSub:(XMPPPubSub *)sender didSubscribe:(XMPPIQ *)iq;
- (void)xmppPubSub:(XMPPPubSub *)sender didUnsubscribe:(XMPPIQ *)iq;
- (void)xmppPubSub:(XMPPPubSub *)sender didCreateNode:(NSString *)node withIQ:(XMPPIQ *)iq;
- (void)xmppPubSub:(XMPPPubSub *)sender didReceiveMessage:(XMPPMessage *)message;
- (void)xmppPubSub:(XMPPPubSub *)sender didReceiveError:(XMPPIQ *)iq;
- (void)xmppPubSub:(XMPPPubSub *)sender didReceiveResult:(XMPPIQ *)iq;
- (void)xmppPubSub:(XMPPPubSub *)sender didPublish:(XMPPIQ *)iq;

@end