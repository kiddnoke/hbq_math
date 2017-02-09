#! /bin/bash 
cd bin/Release/
rm -rf *.log 
./hbq_math_numerical > hbq_math_numerical.log
./hbq_math_searchtable > hbq_math_searchtable.log 

egrep "HBQ_MATH" hbq_math_numerical.log > hbq_math_numerical.HBQ_MATH.log 
egrep "HBQ_MATH" hbq_math_searchtable.log > hbq_math_searchtable.HBQ_MATH.log 
egrep "SYSTEM" hbq_math_numerical.log > hbq_math_numerical.SYSTEM.log 
egrep "SYSTEM" hbq_math_searchtable.log > hbq_math_searchtable.SYSTEM.log 
cat hbq_math_numerical.HBQ_MATH.log | awk '{printf("%s %s %s %s\n" , $1 , $3 ,$4 , $7)}'> hbq_math_numerical.HBQ_MATH.withoutnumber.log
cat hbq_math_searchtable.HBQ_MATH.log  | awk '{printf("%s %s %s %s\n" , $1 , $3 ,$4 , $7)}' > hbq_math_searchtable.HBQ_MATH.withoutnumber.log
cat hbq_math_numerical.SYSTEM.log | awk '{printf("%s %s %s %s\n" , $1 , $3 ,$4 , $7)}' > hbq_math_numerical.SYSTEM.withoutnumber.log
cat hbq_math_searchtable.SYSTEM.log | awk '{printf("%s %s %s %s\n" , $1 , $3 ,$4 , $7)}' > hbq_math_searchtable.SYSTEM.withoutnumber.log