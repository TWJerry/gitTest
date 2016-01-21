<<<<<<< HEAD
adkadakdhadajdlajdlajd;jaja
jialdalj
aldhlad


@property(nonatomic) NSString *subId;
@property (nonatomic,copy) NSString *otherTransport;
@property (nonatomic,copy) NSString *subActTitle;
@property (nonatomic,copy) NSString *isSource;



@property(nonatomic,copy) NSString *cellClass;


- (void)setCellClass:(NSString *)cellClass
{
    _cellClass = cellClass;
    
    if ([cellClass isEqualToString:@"waitReceive"]) {
        self.centerBtn.hidden = NO;
    }else {
        self.centerBtn.hidden = YES;
    }
    
}



@property (weak, nonatomic) IBOutlet UIButton *centerBtn;


- (void)awakeFromNib {
    [self setSelectionStyle:UITableViewCellSelectionStyleNone];
    
    //    UIImage* stretchImage = [[UIImage imageNamed:@"btn_outlinelightgray"]
    //        resizableImageWithCapInsets:UIEdgeInsetsMake(4, 4, 4, 4)];
    
    self.leftButton.layer.cornerRadius = 3;
    self.leftButton.layer.borderWidth = 1;
    self.leftButton.layer.borderColor = [UIColor colorFromHexString:@"38CD77"].CGColor;
    [self.leftButton setTitleColor:[UIColor colorFromHexString:@"38CD77"] forState:UIControlStateNormal];
    
    self.centerBtn.layer.cornerRadius = 3;
    self.centerBtn.layer.borderWidth = 1;
    self.centerBtn.layer.borderColor = [UIColor colorFromHexString:@"888888"].CGColor;
    
    self.rightButton.layer.cornerRadius = 3;
    self.rightButton.layer.borderWidth =1;
    self.rightButton.layer.borderColor = [UIColor colorFromHexString:@"727272"].CGColor;
    [self.rightButton setTitleColor:[UIColor colorFromHexString:@"727272"] forState:UIControlStateNormal];
    
    [self.centerBtn setTitle:@"物流跟踪" forState:UIControlStateNormal];
    [self.centerBtn addTarget:self action:@selector(transport:) forControlEvents:UIControlEventTouchUpInside];
    [self.centerBtn setTitleColor:[UIColor colorFromHexString:@"8c8c8c"] forState:UIControlStateNormal];
    self.centerBtn.titleLabel.font = [UIFont systemFontOfSize:14];
    
    self.centerBtn.hidden = YES;
    self.rightButton.layer.cornerRadius = 3;
    self.rightButton.layer.borderWidth =1;
    self.rightButton.layer.borderColor = [UIColor colorFromHexString:@"FA7F0B"].CGColor;
    //    [self.leftButton setBackgroundImage:stretchImage forState:UIControlStateNormal];
    //    [self.rightButton setBackgroundImage:stretchImage forState:UIControlStateNormal];
    [self.rightButton setTitleColor:[UIColor colorFromHexString:@"FA7F0B"] forState:UIControlStateNormal];
    [super showBottomSeparator];
}

- (void)configWithOrderInfo:(OrderInfo*)orderInfo indexPath:(NSIndexPath*)indexPath {
    _indexPath = indexPath;
    self.leftButton.hidden = NO;
    self.rightButton.hidden = NO;
    
    switch ([orderInfo orderType]) {
        case kOrderTypeWaitPay: {
            [self.leftButton setTitle:contactSeller forState:UIControlStateNormal];
            [self.rightButton setTitle:cancelOrder forState:UIControlStateNormal];
        } break;
        case kOrderTypeNoSend: {
            [self.leftButton setTitle:contactSeller forState:UIControlStateNormal];
            [self.rightButton setTitle:remindSendProduct forState:UIControlStateNormal];
        } break;
        case kOrderTypeAlreadySend: {
            [self.leftButton setTitle:contactSeller forState:UIControlStateNormal];
            [self.rightButton setTitle:verifyReceive forState:UIControlStateNormal];
        } break;
        case kOrderTypeWaitEvaCanReturn: {
            [self.leftButton setTitle:evaluate forState:UIControlStateNormal];
            [self.rightButton setTitle:applyReturn forState:UIControlStateNormal];
        } break;
        case kOrderTypeWaitEvaNoReturn: {
            self.leftButton.hidden = YES;
            [self.rightButton setTitle:evaluate forState:UIControlStateNormal];
        } break;
        default:
            break;
    }
}

- (void)transport:(UIButton *)btn
{
    if ([self.delegate respondsToSelector:@selector(transportDetailIndexPath:)]) {
        [self.delegate transportDetailIndexPath:_indexPath];
    }
}

- (IBAction)optionButtonPressed:(id)sender {
    NSString* title = [sender titleForState:UIControlStateNormal];
    if ([title isEqualToString:contactSeller]) {
        if ([self.delegate respondsToSelector:@selector(contactSellerInIndexPath:)]) {
            [self.delegate contactSellerInIndexPath:_indexPath];
        }
    } else if ([title isEqualToString:applyReturn]) {
        if ([self.delegate respondsToSelector:@selector(applyReturn)]) {
            [self.delegate applyReturn];
        }
    } else if ([title isEqualToString:cancelOrder]) {
        if ([self.delegate respondsToSelector:@selector(cancelOrderInIndexPath:)]) {
            [self.delegate cancelOrderInIndexPath:_indexPath];
        }
    } else if ([title isEqualToString:verifyReceive]) {
        if ([self.delegate respondsToSelector:@selector(verifyReceiveInIndexPath:)]) {
            [self.delegate verifyReceiveInIndexPath:_indexPath];
        }
    } else if ([title isEqualToString:evaluate]) {
        if ([self.delegate respondsToSelector:@selector(evaluateInIndexPath:)]) {
            [self.delegate evaluateInIndexPath:_indexPath];
        }
    } else if ([title isEqualToString:remindSendProduct]) {
        if ([self.delegate respondsToSelector:@selector(remindSendProductInIndexPath:)]) {
            [self.delegate remindSendProductInIndexPath:_indexPath];
        }
    }
}

- (void)setCellClass:(NSString *)cellClass
{
    _cellClass = cellClass;
    
    if ([cellClass isEqualToString:@"waitReceive"]) {
        self.centerBtn.hidden = NO;
    }else {
        self.centerBtn.hidden = YES;
    }
    
}
