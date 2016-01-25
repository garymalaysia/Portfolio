def factcheck(a,e,phi,col):
    if a == 1:
        print "we found 'd' ->",col
        print "Fact checking..."
        if (e*col % phi)==1:
            print a," it is correct!"
            return (e*col % phi)
    else:
        print a," is not correct."

p=447016317160975125856982388571
q=426057714627379979519513160083
n=p*q
print "The 'n' Value is -> ",n
phi=(p-1)*(q-1)
col1=(p-1)*(q-1)
col2=col1
print "The 'phi'value is->",phi
e=17 # for question #39, We change the 'e' to 17.
e2=1
print "*****column 1*****"
row1=col1/e
print "step 1 phi1 is-> ",row1
col1=col1-(row1*e)
print "step 2->" ,col1
tmp=e/col1

print"step 3->" , tmp
t1=tmp

col1=tmp*col1
print "step 4->" ,col1
tmp2=e-col1

print "step 5->", tmp2
t2=tmp2

tmp3=col1/tmp2
print "step 6->" ,tmp3
t3=tmp3

tmp4=tmp2*tmp2
print "step 7->", tmp4
t4=tmp4

tmp5=col1-tmp3
print "step 8->",tmp5
t5=tmp5

print "*****Column 2*****"
col2=col2-(row1*e2)
print"step 1->", col2
col=tmp*col2
print "step 2->", col
col=e2-col
if col< 0:
    col=col % phi
    print col
        
        
new=col*tmp3
print "step 3->",new
row3=col2-new



print "step 4->",row3
if row3< 0:
    row3=row3 % phi
    print row3
print "\n"
print "Fact Checking is happening here.."
factcheck(t1,e,phi,col)
print "\n"
factcheck(t2,e,phi,col)# both Tmp2 and tmp4 has 1 as their value.
print "\n"
factcheck(t3,e,phi,col)
print "\n"
factcheck(t4,e,phi,col)
print "\n"
factcheck(t5,e,phi,col)