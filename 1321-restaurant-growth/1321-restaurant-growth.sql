# Write your MySQL query statement below
select visited_on,amount,round(amount/7,2) as average_amount from 
(select visited_on,sum(amount) over (order by visited_on range between interval 6 day preceding and current row) as amount from (SELECT
            visited_on,
            SUM(amount) AS amount
        FROM Customer
        GROUP BY visited_on
    ) d
) t
WHERE visited_on >= (
    SELECT DATE_ADD(MIN(visited_on), INTERVAL 6 DAY)
    FROM Customer
)
ORDER BY visited_on;