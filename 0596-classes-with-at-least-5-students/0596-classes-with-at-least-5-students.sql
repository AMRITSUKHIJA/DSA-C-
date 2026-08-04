# Write your MySQL query statement below
-- select class from Courses where count(class)>=5 group by class ❌
select class from Courses group by class having count(class)>=5;